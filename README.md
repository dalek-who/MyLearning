

To Compile:
- Bwapi 4.1.2 & BWTA (set environment viariables with names BWAPI_DIR & BWTA_DIR)
- Open src/cpac/VisualStudio/cpac.sln in VS2013
- Select Release mode
- Build the cpac project
- Output will go to src/cpac/bin/cpac.dll

Tournament Setup:
- Copy dll/cpac.dll (or the above compiled dll) to the tournament cpac/AI folder
- Copy dll/cpac.json to the tournament cpac/AI folder
- Set bots: {"BotName": "cpac", "Race": "Zerg", "BotType": "dll", "BWAPIVersion": "BWAPI_412"}

Directory Structure:
- dll/
	- cpac.dll
	- cpac.json
- src/
	- cpac/
		- cpac.json
		- bin/
		- Source/
			...
		- VisualStudio/
			...
			
Instroduction:
- Based on Steamhammer by Jay Scott
