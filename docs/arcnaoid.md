# ARCANOID

Arcanoid game created with Cpp and QT.  

<br/>    

## Table of content
----------------------

1. Dictionary
2. Single player game

<br/>    

## 1. Dictionary
------------------

### 1.1 Board
Object controlled by user, which bounces a **ball [1.2]** and consumes **effect cristal [1.4]**.

### 1.2 Ball
Object which constantly moves and bouncing on every collision with board, block or any edge of game area but bottom.

### 1.3 Block 
Object destoryable by ball.


### 1.4 Effect
Addtional functionalities granted for: **board [1.1]** or **board [1.2]** or modification of existing properties of above objects. 
 
### 1.5 Effect cristal
Object which appears in the place of destroyed block. It moves down the screen and can be consumed by **board [1.1]**.  

### 1.6 Game area
Visual area where the game is played.  

### 1.7 User/Player
Person who controls board and play a game.  

<br/>    

## 2. Game  
---------------------------
### 1.1 Description  
Game is a main fuctionality of project.  
To win **Player** needs to achive game **aim[2.3]**.
Player can loose when he achive **defeat codition[2.4]**.

### 2.2 Actors
In single player game there are following actors:  

* **Board[1.1]** (one) 
* **Ball[1.2]** (one)
* **Block[1.3]** (many)
* **Player[1.6]**

### 2.3 Aim and win condition
The aim of game is to destroy all blocks in the screen by **ball[1.1]**.  
After reaching this aim game is win.

### 2.4 Defeat condtion
Game loos occures when amount of **Lives[2.5]** reaches value of 0.


### 2.5 Lives
The amount of chances given to **Player** during **Game**.  
This amount is decremented when **Ball** touches bottom edge of **Game area**  
Is incremented when **New Live Effect Cristal** is consumed by **Board**.

Lives are showed on the screen as *heart icons* which amount corresponds to amount of lives.  

### 2.6 Effects
Effects are attached to **Game** and starts to exerting influence on chosen objects when **Effect Cristal** is consumed by **Board**.  

### 2.7 Blocs placement
Blocs are placed above board in some distance.

### 2.8 Game mechanics:

#### 2.8.1 Beggining:  
At the beggining there are granted an amount of lives. This amount is defined by game configuration.  
No **Effects** are active.  

#### 2.8.2 Starting:
Game starts on **Player's** signal, after detection of mentioned signal ball starts to move. This movement is described by vector:  

``` 
v = k * [1;1]

where:
v - velocity vector
k - scalar of speed (it's initial value is defined by game configuration)  
```

It follows that balls initial vector is diracted at an angle of 45deg to the upper right corner of **Game area**.


#### 2.8.3 Bouning:
When ball hits board, block or any edge of game area but bottom, then it changes its movement direction.
Velocyty vector of ball changes on collsision in following way:  

```
If ball hits vertical surface ( __ ) :  
[x,y] -> [x,-y]

If ball hits vertical surface ( | ) :  
[x,y] -> [-x, y]
```

