
This is a brief overview of the main classes in the game:

1-
Game class contains the different phases of the game. Each phase is coded in its corresponding function (behavior)

Game::Behavior_intro presents a dialog describing the rules
Then Game::Behavior_countdown will present the count down before starting to play
Game::Behavior_playing is where the game really takes place.

2-
Game contains a board, a score and a time counter objects.

3-
The board class contains 64 tiles. 
Each tile can be one of 5 types.

4-
The classes Game, Board, Score, TimeOut, Intro, CountDown are derived from the class Object

5-
ObjectsManager is a class that calls Update and Draw functions of Object instances it has in its double linked list.
Objects contained between the activeobjects.next and activeobjectstail.prev are updated and drawn.
Objects contained between the activeobjectstail.next and activeobjects.prev are drawn only. This allows the board, tiles, score and time counter to be drawn without being updated when the intro, the count down and the time-out objects are in the front.

