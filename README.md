# Remember
Experimental project made in Unreal Engine 4.

Simple experimental prototype of a puzzle game made in UE4.
Idea based on the Theme of GGJ 2016 "Ritual".

![Game screen](/screens/gamescreen1.PNG?raw=true "Game Screen")

## Gameplay:
The player has to navigate through a small grid containing of platforms to the other side. Some of the platforms will fall down, and the player will have to start over.
Which platforms will fall is determined by the moves the player makes in the levels before.
In order to advance sucessfully in the game the player has to remember every step taken up to the last failure.

The initial floor is randomly generated which means that every new game will test the players ability to Remember again.

![Gameplay gif](/screens/gamegif.gif?raw=true "Gameplay gif")

### Technical details
This experimental version uses matrix multiplication for determining the falling platforms and a random seed for the first level.
Assets used are mainly UE4 standard assets.
