// Note: Please maximize this text file to understand it completely, minimizing this window may result in the layout being disfigured
Extra info:

// The start/first scene must be called "StartRoom" or it will not be registered by the engine as the adventures first scene and will not begin the game as there needs to be a start scene in any text adventure game.

// There must be an end scene in, if there is no end scene than the adventure will continue infinitely and can never be finished. To declare that a scene is an end scene you must call the scenes ID "EndScene" otherwise the engine will not recognise it as an end scene.

Layout:

// This is the layout of a scene, the numbers on the right point to a certain component of the scene and can be read in the layout information area (<----|-1 = 1. My information).
// Note: The numbers on the right and the arrows attached to those numbers are NOT apart of the scene layout.

[Scene] <------------------------------|-1
ID=RoomName <--------------------------|-2
Description=Rooms description. <-------|-3
[1. First choice]->[SceneToGoTo]  <----|-4
[2. Second choice]->[SceneToGoTo] <----|-5
[3. etc]->[SceneToGoTo] <--------------|-6
end_scene; <---------------------------|-7
end_adventure; <-----------------------|-8

Layout information:

1. Declares what the engine is about to read is a scene.

2. Gives a name or ID to the scene, in this case this scene will be called "RoomName".

3. The description of the scene, tells the player where they are in the adventure and maybe some extra info to help them in there journey.

4. Holds the choice data. The text inside the first "[]" must contain the description of where the choice leads to for the player as well as what number choice it is
(if it's the first choice than it must be called "1. My choice") this must then be followed by a "->", this tells the engine that the next "[]" is going to contain a Scene* pointer.
The last "[]" tell the engine what scene this choice will lead to, this will contain a Scene* pointer.
A scene name MUST be placed inside the last "[]".
(e.g. if a choice is leads to a "MyRoom" than the text inside the last "[]" must be called "MyRoom" exactly or the engine will not recognise the scene pointer as a valid scene)

5. This is the second choice of the scene which follows all the previous rules of choice 1 and must be numbered as "2. MyChoice" as this is the second choice of the scene.

6. This is the third choice which follows all previous choice rules.

7. The "end_scene;" keyword is ALWAYS placed at the bottom/end of a scene which tells the engine that this is the end of the current scene and to add this scene to the adventures scene collection.
The "end_adventure;" must be written EXACTLY how it is written here or the engine will not save the previously read scene and will continue reading unto the next scene available.
This will cause issues with the adventure and it's scene collection as all scenes inside the adventure will be mixed together and cause issues.

8. The "end_adventure;" keyword is ALWAYS placed at the bottom/end of the text file. This indicates to the engine that all available scenes have been added to the adventures scene collection.
The engine will then stop reading the current adventure text file and move on to the next available adventure text file (if there is one).
The "end_adventure;" must be written EXACTLY how it is written here or the engine will not save the current adventure properly and may cause errors.




