# Pathfinding-Visualiser

![](https://github.com/ewerae/Pathfinding-Visualiser/blob/main/pathfinder.gif)

WOP Pathfinding visualiser. 
Currently has A* search algorithm, if I implemented it right, it looks right...

Uses the octile heuristic method, apparently more accurate in obtaining diagonal paths so.

Small minor quality of life details added:
- Run and Reset
- Can override the state the tile has just by clicking with another tile state, no constant resetting or deleting certain tiles.

Like I said, work in progress. There are bugs, not entirely in the search algorithm but more about being able to click buttons whilst running etc.
Although thinking about it now, this heuristic method actually can pierce through diagonal obstacle walls. For example, if a grid of {1, 0}, {0, 1}. A path forming through the 0s can be considered a valid path.
Besides that the algorithm should work. 

Annoyingly I have no idea on how to speed up calculation time either in SFML. I'm using a virtual machine to use linux as some pre-requisites to windows SFML was driving me crazy and for Linux it was a simple click of the download button.

I'll add more search algorithms.
