# ARCANOID


Arcanoid game created with Cpp and QT.  

<br/>    

## Table of content
----------------------

1. Dictionary
2. Game
3. Ball                 
4. Board
5. Blocks               | <font color='red'>**TODO**</font>
6. Effects              | <font color='red'>**TODO**</font>
7. Game Area            | <font color='red'>**TODO**</font>
8. Navigation           | <font color='red'>**TODO**</font>

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
### 2.1 Description  
Game is a main fuctionality of project.  
To win **Player** needs to achive game **aim[2.3]**.
Player can loose when he achive **defeat codition[2.4]**.

### 2.2 Actors
In game there are following actors:  

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

### 2.6 Scoring
Every game stores amount of points gained by the **Player**. This amount is called **score**.    
Every time when ball destroys  **block** **scroe** is increment by value determinated in game configuration.  

During game play scrore is displayed in upper-right corner of screen.


### 2.7 Effects
Effects are attached to **Game** and starts to exerting influence on chosen objects when **Effect Cristal** is consumed by **Board**.  

### 2.8 Blocs placement
Blocs are placed above board in some distance.

### 2.9 Game mechanics:

#### 2.9.1 Beggining:  
At the beggining there are granted an amount of lives. This amount is defined by game configuration.  
No **Effects** are active.  
Ball is sticking to board.
User can move board right and left.

#### 2.9.2 Starting:
Game starts on **Player's** signal, after detection of mentioned signal ball starts to move.  
*More about ball movement: **[3.3]***.  

#### 2.9.3 Bouning:
*Bouncing has been described here: **[3.4]** *

#### 2.9.4 Collision with bottom egde of **Game area**
If amount of **Lives** are greater than 0 than it will be decremented and ball will again stick to board.  
Game can start again **[2.9.2]**.

#### 2.9.4 Game over:
Game can finish with **Player's** **win [2.3]** or **lose[2.4]**.
After that on the screen occurs info about game result.  

If player wins he can input his score with label of his choise to **Ranking** storage.  
Otherwise he is navigated to **Main menu** page.  


<br/>

## 3. Ball  
---------------------------

### 3.1 Description

Ball is an constantly moving object which bounces on every collision with any of **Collistion Object [3.2]** in **Game Area**:


### 3.2 Collisiton objects
* Game area upper edge
* Game area left edge
* Game area right edge
* Board
* Block

### 3.3 Movements and movement vector
The **ball** is constantly moving, and it's movement can be described by vector:

```
v = k * [x;y]

where:
v - velocity vector
k - scalar of speed (it's initial value is defined by game configuration)  

x - x dimension coordinate : 1 by default
y - y dimension coordinate : 1 by default
```

That follows that balls initial vector is diracted at an angle of 45deg to the upper right corner of **Game area**.

It can be changed in game configuration.


### 3.4 Bouncing mechanics
When ball hits any of **Collision object [3.2]**, then it its movement direction changes in following way:  

```
If ball hits vertical surface ( __ ) :  
[x,y] -> [x,-y]

If ball hits vertical surface ( | ) :  
[x,y] -> [-x, y]
```
 
### 3.5 Effects influence
The **Ball's** phisics (**movement [3.2]** or **bouncing mechanics[3.3]**) can be changed where new effect is assigns to **Game**

For ex. the **speed** of **ball** can be incresed od decresed, or bouncing angle can be changed.

*Effects are descirbed here : **[6]***

<br/>

## 4. Board
---------------------------

### 4.1 Description 
Board is an object controlled by **Player**, which is used to bounce ball.  
It is intend to protect the bottom edge of **Game Area** so that it is not crossed by ball's motion trajectory.


### 4.2 Position in the **Game area**
It is positioned in the bottom of **Game Area** at short distance from bottom edge.


### 4.3 Motion

The velocity of **board** can be described with vector:

```
v = speed * [x, 0], where:

v       -   vector of velocity
speed   -   always positive scalar value (+), determines speed

x       -   |x| is unchangable and defined in game configuration
            but its sign (- / +) can be changed and it defines 
            direction of boards movement.
```

#### 4.3.1 Restrictions
Board motion is controlled by user. It can move only in **HORIZONTAL** directions:
* RIGHT
* LEFT  

It also can not cross *right* or *left* edge of **Game Area**.

#### 4.3.2 Speed
Board moves with predetermined speed.
This speed can changed dynamicly during game play.
The default speed of board is defined in game properties and can  


### 4.4 Length and thickness
Default Length and thickness are defined in game config.
Thickness cant be changed dynamicly during game play.
Length can be changed  during game due to the *effects influence **[3.5]***.


### 4.4 Collision with ball

Board is one of object that can bounce a ball. *look: [3.2]*  
Therefore every collision results in ball bounce.


### 3.5 Effects influence
Board properties such as speed or length can by *Efects*  
*Effects are descirbed here : **[6]***

