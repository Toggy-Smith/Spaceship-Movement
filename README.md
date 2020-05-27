# Spaceship Movement
 
## How can I run this program?

At the top of this page, there will be a series of tabs. Below that is another series of tabs which should list commits, branches, packages, releases, etc. Click on the release tab and then click on the .zip file there to download the program.

## How was this program written?

This program was written in a day in the C++ language and uses the Simple Fast Multimedia Library (SFML) to draw graphics.

## What is the purpose of this program?

I was testing my own library: the Simple Vectors Library (SVL). The program features a spaceship which has movement controlled using vectors.

## How does it work?

A direction vector is created at the start of each iteration of the game loop. Keyboard input via the arrow keys changes this direction vector.

For example, if the down arrow key is pressed then ```1``` is added to the y component of the direction vector and then if the right arrow key is also pressed ```1``` is also added to the x component of the direction vector. This means that the x, y values of the direction vector will be ```1, 1```. As a result, the vector will have a magnitude of ```1.414 (3 d.p)```. To make the magnitude ```1``` while retaining the direction of the direction vector, we normalise it. In this case, after normalisation the direction vector will have x and y values of ```0.707 (3 d.p)```.

The direction vector is then multiplied by the spaceship's speed to create a "movement" vector. It's important to note at this stage that if the direction vector had not been normalised then the spaceship would have been able to travel a greater distance by moving diagonally instead of along the x or y axis.

This movement vector is then added onto the spaceship's velocity vector. We then check the magnitude of the velocity vector and we limit it to a certain amount to ensure our spaceship doesn't reach ridiculous speeds if you keep holding down the key to travel in one direction.

We also decrease the velocity vector's magnitude by a certain amount (the "movement friction") so that our spaceship gradually slows down over time.

Finally, the spaceship's position is moved based on the velocity vector. (```spaceship.x += velocityVector.x``` and ```spaceship.y += velocityVector.y```).
