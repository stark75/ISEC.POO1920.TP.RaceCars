# RaceCars

RaceCars is a racing car simulator developed for Object-Oriented Programming class from Coimbra Engineering Academy.

## Contents
-   [Background](#background)
-   [Dependencies](#dependencies)
    - [Consola library](<#consola library>)
        - [Consola prerequisites](<#consola prerequisites>)
-   [Usage](#usage)
    - [Commands](#commands)
        - [Mode 1 - Configuration](<#mode 1 - configuration>)
        - [Mode 2 - Championship](<#mode 2 - championship>)



## Background
To test our skills and our knowledge about the subject content, we were asked to develop a C++ Race Car Simulator. The Simulator should contain aspects like Car, Pilot, Racetrack, and Garage and implement them in Oriented-Object Programming paradigm.

## Dependencies

### Consola library
In order to help us develop the Visual UI, we were given a *Consola* library to control the console, which is included inside the [project](../TP-POO1920-RaceCars/Consola "Consola Library").

#### Consola prerequisites

- C++11 or above
- Windows NT or above operating system.

## Usage

### Commands

#### **Mode 1 - Configuration**
|Command|Description
|--- |---
|carregaP *filename*|loads Pilots from a text file
|carregaC *filename*|loads Cars from a text file
|carregaA *filename*|loads Racetracks from a text file
|cria *typeLetter* *ObjectData*|adds an object from any type (**c** - car, **p** - pilot, **a** - racetrack) and Object Data must be the one that should exist to create an object of that type. Example: *cria p crazy John Jones* creates a Crazy Pilot named John Jones
|apaga *typeLetter* *ObjectIdentifier*|deletes an object of a certain type. Example: *apaga p John Jones* deletes a pilot named John Jones
|entranocarro *carID* *PilotName*|assigns a Pilot to a Car. If the car is already assigned, nothing happens
|saidocarro *carID*|removes the pilot from the car
|lista|displays all the info about the objects inside the simulator
|savedgv *dgvName*|creates a backup of the DGV (Cars and Pilots Container)
|loaddgv *dgvName*|loads the backup of the DGV
|delddgv *dgvName*|deletes the backup of the DGV
|championship *Track1*| generates a championship with a single Racetrack
|championship *-Track1 -Track2* ... *-TrackN*| generates a championship with multiple Racetracks, starting in *Track1*. It loads every car assigned to a pilot into that championship. Does nothing if there isn't at least 2 cars assigned.
#### **Mode 2 - Championship**
|Command|Description
|--- |---
|listacarros|displays all the info about the cars inside the garage and in the race
|carregabat *carID* *nQuantity*|charges the car's energy by *nQuantity*
|carregatudo|charges all cars in the Racetrack
|corrida|starts the race in the current Racetrack
|acidente *carID*|generates an acident
|stop *pilotName*|orders the pilot to stop the car
|destroi *carID*|destroys the car
|passatempo *nSeconds*|simulates n seconds of the race
|log|displays the simulator's log