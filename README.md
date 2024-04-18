# ARCADE

> Epitech Project: **B-OOP-400-RUN-4-1-arcade**

_Language :_ `C++`

_Compilation method :_ `CMake`

_Dependencies needed :_
- `SFML 2.5.1`
- `OPENGL`
- `SDL 2`
- `NCurses`

## Introduction

We had 4 weeks to develop a software which handles several `Graphical
Libraries` and several `Games Modules` which basically represent an arcade.

In this project you can:
- _Play_ to our snake's game and our centipede's game.
- _Switch_ between 4 graphical libraries (NCurses, SFML, OpenGL, SDL2).

But we will show you how to create your **_OWN_** `Game Module` and your **_OWN_** `Display Module`.

## Concept

Our software is divided into three main parts.

### Core

The **Core** is the handler between the `Game Module` and the `Display Module`.

It is the main program, the **entry point of the user**.

### Game Module

The **Game Module** is the part of the software that handles a game.

For example: you want your arcade to have nibbler's game, so you will code it
as a **Game Module**.

Because `Game Module` defines the behaviour of a game.

### Display Module

The **Display Module** is the part of the software that handles how you want to display your games.

_For example:_ you want your arcade to use `libcaca` to display your games, so you will code it as a **Display Module**.

But you can also use SFML in 2D and 3D, for example. In fact, the `Display Module` is just a way to display stuff on the screen, you can redefine several ways to display in the same **Graphical Library**.

## Create your Game Module

A **Game Module** is basically composed of entities. We created a file format that defines entities globally. Here is an example of how to define entities:

```
char:P
sprite:library/game/Snake/config/assets/player.png
type:PLAYER
#
char:E
sprite:library/game/Snake/config/assets/enemy.png
type:ENEMY
#
char:W
sprite:library/game/Snake/config/assets/wall.png
type:ENVIRONMENT
#
char:A
sprite:library/game/Snake/config/assets/apple.png
type:OBJECT
```

- ### Configuration files
---

Your project **MUST** have this files:
- entities.etib
- map.txt

* ### entities.etib

    * This define the char which will represent the entity of this type:
        ```
        char:*a_basic_character*
        ```

    * A picture (or more generally a ressource) is associated to the entity:
        ```
        sprite:path/to/the/ressource/of/the/entity
        ```

    * And a type define the entity, which can be type of:
        ```
        type:PLAYER
        type:OBJECT
        type:ENEMY
        type:ENVIRONMENT
        ```

    * > This 3 properties are mandatory, the project will not work if you miss one of this properties.

    * Each entity definition is separated by a line with a single '#' on the line:
        ```
        char:P
        sprite:library/game/Snake/config/assets/player.png
        type:PLAYER
        #
        char:E
        sprite:library/game/Snake/config/assets/enemy.png
        type:ENEMY
        #
        char:W
        sprite:library/game/Snake/config/assets/wall.png
        type:ENVIRONMENT
        ```

* ### map.txt

    * Your map is basically the representation of your game when you just start it.
    * It will look something like this:
        ```
        WWWWWWWWWWWWW
        W           W
        W           W
        W           W
        W      P    W
        W           W
        W           W
        W           W
        W           W
        W  E        W
        WWWWWWWWWWWWW
        ```
    * It refered to the **entities.etib** conf file of the game.

* ### savegame.etib _(Work In Progress)_

- ### The Game Module
---

- To initialize the game with the configuration files, you will use:
    ```
    EGE::AGameModule::init(gameFolder);
    ```
    Where `gameFolder` is the folder which contains the previous `entities.etib` and `map.txt`.

- Now you just have to _override_ the following functions:
    - EGE::AGameModule::createPlayer(...);
    - EGE::AGameModule::createEnemy(...);
    - EGE::AGameModule::createObject(...);
    - EGE::AGameModule::createEnvironment(...);

- But you will also have to _override_:
    ```
    EGE::AGameModule::load(...)
    ```
    It handles the initialization of the game with the `Display Module`, in case of you have a specific behaviour during initialization.

> Once you have done the tasks before, free to do what you want for your game !

## Create your Display Module

It is the hardest and longest part of the process...

For a basic implementation of the mandatories modules needed by the engine, you have to implement the following objects and classes:
- Sprite
- Text
- Button
- Window
- Event

And in the `Display Module` you have to _override_ the following methods:
- EGE::ADisplayModule::createSprite(...);
- EGE::ADisplayModule::createText(...);
- EGE::ADisplayModule::createButton(...);

The rest of the behaviour will be defined in the Sub Modules like Sprite, etc...