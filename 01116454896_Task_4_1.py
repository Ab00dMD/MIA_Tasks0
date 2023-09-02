# Define a villain class with attributes for health, energy, shield, and name.
class villian:
    def __init__(self, name):
        self.health = 100
        self.energy = 500
        self.shield = 0.0
        self.name = name
 
# Define a weapon class with attributes for name, energy cost, damage, and resource       
class weapon:
    def __init__(self, name,energy, damage, resource):
        self.name = name
        self.energy = energy
        self.damage = damage
        self.resource = resource
     
    # Check if there is enough energy and resource to use the weapon. 
    def isEnough(self, attacker):
        return (self.energy <= attacker.energy and self.resource>0)  
    
    # Use the weapon on the opponent if enough energy and resource are available.  
    def use(self,attaker ,opp):
        if(self.isEnough(attaker)):
            attaker.energy -= self.energy
            opp.health -= (1-opp.shield)*self.damage
            self.resource -= 1
        else:
            print('No Enough resources or Energy')
    
    
# Define a shield class with attributes for name, energy cost, save value, and resource  
class shield:
    def __init__(self, name, energy, save, resource):
        self.name = name
        self.energy = energy
        self.save = save
        self.resource = resource
    
    # Check if there is enough energy and resource to activate the shield.
    def isEnough(self, person):
        return (self.energy <= person.energy and self.resource>0)
    
    # Activate the shield if enough energy and resource are available.
    def saveMe(self, person):
        if (self.isEnough(person)):
            person.shield = self.save
            self.resource -=1
        else:
            print('No Enough resources or Energy')
        
    
# Create Gru's Gadgets
freeze_gun = weapon("Freeze Gun", 50, 11, 9999)
electric_prod = weapon("Electric Prod", 88, 18, 5)
mega_magnet = weapon("Mega Magnet", 92, 10, 3)
kalman_missile = weapon("Kalman Missile", 120, 20, 1)    

energy_barrier = shield("Energy-Projected BarrierGun", 20, 0.4, 999)
selective_permeability = shield("Selective Permeability", 50, 0.9, 2)

# Create Vector's Gadgets
laser_blasters = weapon("Laser Blasters", 40, 8, 9999)
plasma_grenades = weapon("Plasma Grenades", 56, 13, 8)
sonic_resonance_cannon = weapon("Sonic Resonance Cannon", 100, 22, 3)

energy_net_trap = shield("Energy Net Trap", 15, 0.32, 9999)
quantum_deflector = shield("Quantum Deflector", 40, 0.8, 3)

# Create Gru and Vector as villain objects.  
Gru = villian('Gru')
vector = villian('Vector')

# Define functions to display Gru's and Vector's weapons and shields
def ShowGruWeap():
    print( 'id- Name, Energy, Resource')
    print(f'1- {freeze_gun.name}, {freeze_gun.energy}, {freeze_gun.resource}')
    print(f'2- {electric_prod.name}, {electric_prod.energy}, {electric_prod.resource}')
    print(f'3- {mega_magnet.name}, {mega_magnet.energy}, {mega_magnet.resource}')
    print(f'4- {kalman_missile.name}, {kalman_missile.energy}, {kalman_missile.resource}')
def ShowVectorWeap():
    print( 'id- Name, Energy, Resource')
    print(f'1- {laser_blasters.name}, {laser_blasters.energy}, {laser_blasters.resource}')
    print(f'2- {plasma_grenades.name}, {plasma_grenades.energy}, {plasma_grenades.resource}')
    print(f'3- {sonic_resonance_cannon.name}, {sonic_resonance_cannon.energy}, {sonic_resonance_cannon.resource}')

def ShowGrushield():
    print( 'id- Name, Energy, Resource')
    print(f'1- {energy_barrier.name}, {energy_barrier.energy}, {energy_barrier.resource}')
    print(f'2- {selective_permeability.name}, {selective_permeability.energy}, {selective_permeability.resource}')
def ShowVectorshield():
    print( 'id- Name, Energy, Resource')
    print(f'1- {energy_net_trap.name}, {energy_net_trap.energy}, {energy_net_trap.resource}')
    print(f'2- {quantum_deflector.name}, {quantum_deflector.energy}, {quantum_deflector.resource}')
        

# start the game loop
round = 1
while(Gru.health>0 and vector.health>0):
    # To avoid getting stuck in an infinite loop
    if(Gru.energy<20 or vector.energy<15):
        break
    
    print('round: ',round)
    choice = input('Gru\'s turn atk/def:')
    choice.lower()
    if(choice == 'atk'):
        ShowGruWeap()
        choice = int(input('weapon number: '))
        match choice:
            case 1:
                freeze_gun.use(Gru, vector)
            case 2:
                electric_prod.use(Gru, vector)
            case 3:
                mega_magnet.use(Gru, vector)
                Gru.shield = 0.2
            case 4:
                vector.shield = 0
                kalman_missile.use(Gru, vector)
                
    if(choice == 'def'):
        ShowGrushield()
        
        choice = int(input('shield number: '))
        match choice:
            case 1:
                energy_barrier.saveMe(Gru)
            case 2:
                selective_permeability.saveMe(Gru)
    
    choice = input('Vector\'s turn atk/def:')
    choice.lower()
    if(choice == 'atk'):
        ShowVectorWeap()
        
        choice = int(input('weapon number: '))
        match choice:
            case 1:
                laser_blasters.use(vector, Gru)
            case 2:
                plasma_grenades.use(vector, Gru)
            case 3:
                sonic_resonance_cannon.use(vector, Gru)
                
    if(choice == 'def'):
        ShowVectorshield()
        
        choice = int(input('shield number: '))
        match choice:
            case 1:
                energy_net_trap.saveMe(vector)
            case 2:
                quantum_deflector.saveMe(vector)
    
    print(f"{Gru.name} Health = {Gru.health}, Energy =  {Gru.energy}")
    print(f"{vector.name} Health = {vector.health}, Energy =  {vector.energy}")
    round+=1
    print(50*'=')

# Determine the winner based on health.
if(Gru.health>vector.health):
    print(f"{Gru.name} WIN!! WIN!! WIN!!")
elif(Gru.health==vector.health):
    print('it\'s a TIE!!')
else:
    print(f"{vector.name} WIN!! WIN!! WIN!!")
