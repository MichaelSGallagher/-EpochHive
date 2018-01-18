/*
	Update the parameters for a mission in the list of missions running at that time.
	Call with the name of the marker associated with the mission and either "Active" or "Completed"
	by Ghostrider [GRG]
	Last modified 1-22-17
	
	--------------------------
	License
	--------------------------
	All the code and information provided here is provided under an Attribution Non-Commercial ShareAlike 4.0 Commons License.

	http://creativecommons.org/licenses/by-nc-sa/4.0/	
*/
#include "\q\addons\custom_server\Configs\blck_defines.hpp";

params["_mission","_status",["_coords",[0,0,0]] ];

#ifdef blck_debugMode
if (blck_debugLevel > 0) then {diag_log format["_fnc_updateMissionQue :: _mission = %1 | _status = %2 | _coords = %3",_mission,_status,_coords];};
#endif

private["_index","_element","_waitTime"];

_index = blck_pendingMissions find _mission;
if (_index > -1) then
{	
	#ifdef blck_debugMode
	if (blck_debuglevel > 0) then {diag_log format ["_fnc_updateMissionQue :: blck_pendingMissions began as %1",blck_pendingMissions];};
	#endif

	_element = blck_pendingMissions select _index;

	#ifdef blck_debugMode
	if (blck_debuglevel > 0) then {diag_log format["_fnc_updateMissionQue::  -- >> _element before update = %1",_element];}; 
	#endif

	if (toLower(_status) isEqualTo "active") then {
		_element set[6, -1];
		_element set[7,_coords];
	};
	if (toLower(_status) isEqualTo "inactive") then 
	{
		_waitTime = (_element select 4) + random((_element select 5) - (_element select 4));
		_element set[6, diag_tickTime + _waitTime];
		_element set [7,[0,0,0]];
	};

	#ifdef blck_debugMode
	if (blck_debuglevel > 0) then {diag_log format["_fnc_updateMissionQue::  -- >> _element after update = %1",_element];}; 
	#endif

	blck_pendingMissions set [_index, _element];

	#ifdef blck_debugMode
	if (blck_debuglevel > 0) then {diag_log format ["_fnc_updateMissionQue :: blck_pendingMissions after update = %1",blck_pendingMissions];};	
	#endif
}; 


