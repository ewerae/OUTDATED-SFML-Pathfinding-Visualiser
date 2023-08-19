# Pathfinding-Visualiser

![](https://github.com/ewerae/Pathfinding-Visualiser/blob/main/pathfinder.gif)

WOP Pathfinding visualiser. 
Currently has my own version of the A* search algorithm, if I implemented it right. Although, other visualisers I have seen look prettier in their solving time. I will blame this VM and Linux however. It's too slow. That being said, I have no idea on how to speed up calculation time either in SFML, and I'm not entirely certain if my virtual machine is the issue. Alas...

I'm using a VM to use Linux as some pre-requisites for Windows 11 SFML was driving me crazy and for Linux it was a simple click of the download button.

The algorithm uses the octile heuristic method, apparently more accurate in obtaining diagonal paths so.

Small minor quality of life details added:
- Run and Reset
- Can override the state the tile has just by clicking with another tile state, no constant resetting or deleting certain tiles.

Like I said, work in progress. There are bugs, not entirely in the search algorithm but more in being able to click buttons whilst running etc, however, clicking reset will completely fix it all, so at least there's a contingency.

Thinking about it now, this heuristic method actually can pierce through diagonal obstacle walls. For example, a 2x2 grid like so:

{{1, 0}, {0, 1}}. 

A path forming through the 0s would be considered a valid. Besides that the algorithm should work as intended. Actually, I haven't told it what to do if there is no path... moving on...


I'll probably add more search algorithms before I even begin fixing the bugs :D

Note: I've left in my debugging functions to check if everything's working the way I think they are, hence some text when running to check the vector sizes, and nodes etc.
