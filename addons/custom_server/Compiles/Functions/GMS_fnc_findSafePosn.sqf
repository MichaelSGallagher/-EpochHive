// self explanatory. Checks to see if the position is in either a black listed location or near a player spawn. 
// As written this relies on BIS_fnc_findSafePos to ensure that the spawn point is not on water or an excessively steep slope. 
// 
/*
	for ghostridergaming
	By Ghostrider [GRG]
	Copyright 2016
	Last Modified 1-22-17
	--------------------------
	License
	--------------------------
	All the code and information provided here is provided under an Attribution Non-Commercial ShareAlike 4.0 Commons License.

	http://creativecommons.org/licenses/by-nc-sa/4.0/
*/
#include "\q\addons\custom_server\Configs\blck_defines.hpp";

private["_findNew","_coords","_dist","_xpos","_ypos","_newPos","_townPos","_pole"];

_findNew = true;

while {_findNew} do {
	_findNew = false;
	//[_centerForSearch,_minDistFromCenter,_maxDistanceFromCenter,_minDistanceFromNearestObj,_waterMode,_maxTerainGradient,_shoreMode] call BIS_fnc_findSafePos
	// https://community.bistudio.com/wiki/BIS_fnc_findSafePos
	_coords = [blck_mapCenter,0,blck_mapRange,30,0,5,0] call BIS_fnc_findSafePos;
	//diag_log format["<<--->> _coords = %1",_coords];
	
	{
		if ((_x distance2D _coords) < blck_MinDistanceFromMission) then {
			_findNew = true;
		};
	}forEach DBD_HeliCrashSites;
	
	{
		if ( ((_x select 0) distance2D _coords) < (_x select 1)) exitWith
		{
			_findNew = true;
		};
	} forEach blck_locationBlackList;
	
	//diag_log format["#- findSafePosn -# blck_ActiveMissionCoords isEqualTo %1", blck_ActiveMissionCoords];	
	{
		//diag_log format["#- findSafePosn -# blck_ActiveMissionCoords active mission item is %1", _x];
		if ( (_x distance2D _coords) < blck_MinDistanceFromMission) exitWith
		{
			_FindNew = true;
		};
	} forEach blck_ActiveMissionCoords;
	
	//diag_log format["#- findSafePosn -# blck_recentMissionCoords isEqualTo %1", blck_recentMissionCoords];
	{
		private["_oldPos","_ignore"];
		_ignore = false;
		//diag_log format["-# findSafePosn.sqf -#  Old Mission element is %1", _x];
		if (diag_tickTime > ((_x select 1) + 1200)) then // if the prior mission was completed more than 20 min ago then delete it from the list and ignore the check for this location.
		{
			_ignore = true;
			blck_recentMissionCoords= blck_recentMissionCoords - _x;
			//diag_log format["-# findSafePosn.sqf -#  Removing Old Mission element: %1", _x];
		};
		if !(_ignore) then
		{
			//diag_log format["-# findSafePosn.sqf -#  testing _coords against Old Mission coords is %1", _x select 0];
			if ( ((_x select 0) distance2D _coords) < blck_MinDistanceFromMission) then  
			{
				_findNew = true;
				//diag_log format["-# findSafePosn.sqf -#  Too Close to Old Mission element: %1", _x];
			};
		};
	} forEach blck_recentMissionCoords;

	// test for water nearby
	private ["_i"];
	_dist = 100;
	for [{_i=0}, {_i<360}, {_i=_i+20}] do
	{
		_xpos = (_coords select 0) + sin (_i) * _dist;
		_ypos = (_coords select 1) + cos (_i) * _dist;
		_newPos = [_xpos,_ypos,0];
		if (surfaceIsWater _newPos) then
		{
			_findNew = true;
			_i = 361;
		};
	};
	// check that missions spawn at least 1 kkm from towns
	{
		_townPos = [((locationPosition _x) select 0), ((locationPosition _x) select 1), 0];
		if (_townPos distance2D _coords < 200) exitWith {
			_findNew = true;
		};
	} forEach blck_townLocations;
	
	// check for nearby plot pole/freq jammer within 800 meters
	_mod = call blck_fnc_getModType;
	_pole = "";
	if (_mod isEqualTo "Epoch") then {_pole = "PlotPole_EPOCH"};
	if (_mod isEqualTo "Exile") then {_pole = "Exile_Construction_Flag_Static"};
	//diag_log format["_fnc_findSafePosn:: -- >> _mod = %1 and _pole = %2",_mod,_pole];	
	{
		if ((_x distance2D _coords) < 600) then
		{
			_findNew = true;
		};
	}forEach  nearestObjects[player, [_pole], 800];	
	
	// check to be sure we do not spawn a mission on top of a player.	
	{
		if (isPlayer _x && (_x distance2D _coords) < 600) then 
		{
				_findNew = true;
		};
	}forEach playableUnits;
	
	if (toLower(worldName) isEqualTo "taviana") then 
	{
		_tavTest = createVehicle ["SmokeShell",_coords,[], 0, "CAN_COLLIDE"];
		_tavHeight = (getPosASL _tavTest) select 2;
		deleteVehicle _tavTest;
		if (_tavHeight > 100) then {_FindNew = true;};
	};
};

if ((count _coords) > 2) then 
{
	private["_temp"];
	_temp = [_coords select 0, _coords select 1];
	_coords = _temp;
};
_coords;
