/*
	[] call blck_fnc_waypointMonitor;
	
	Scans all groups in  for those that have been stuck in a particular waypoint for an excessive time and checks if they are in combat. 
	If not it directs them to the next waypoint. 
	It uses a timestamp attached to the group that is cleared upon waypoint completion.
	
	By Ghostrider-DbD-
	Last modified 3/14/17
	
	--------------------------
	License
	--------------------------
	All the code and information provided here is provided under an Attribution Non-Commercial ShareAlike 4.0 Commons License.

	http://creativecommons.org/licenses/by-nc-sa/4.0/
*/
#include "\q\addons\custom_server\Configs\blck_defines.hpp";

//diag_log format["_fnc_missionGroupMonitor (4/29:4:09 PM)::-->> running function at diag_tickTime = %1 with blck_fnc_missionGroupMonitor = %2",diag_tickTime,blck_monitoredMissionAIGroups];
#ifdef blck_debugMode
	//diag_log format["_fnc_missionGroupMonitor:: blck_debugMode defined"];
#endif
_fn_allPlayers = {
	private ["_players"];
	_players = [];
	{
		if (isPlayer _x) then {_players pushback _x};
	}forEach playableUnits;
	//diag_log format["_fn_allPlayers::-->> result s %1",_players];
	_players
};

_fn_aliveGroupUnits = {
	private["_grp","_aliveUnits"];
	_grp = _this select 0;
	_aliveUnits = [];
	{
		if ( alive _x) then {_aliveUnits pushback _x};
	} forEach (units _grp);
	_aliveUnits
};

_fn_inCombat = {
	private["_grp","_targets","_players","_aliveUnits"];
	_grp = _this select 0;
	_players = [] call _fn_allPlayers;
	_aliveUnits = [_grp] call _fn_aliveGroupUnits;
	_inCombat = false;
	{
		_targets = _x findNearestEnemy (position _x);
		if !(isNull _targets) exitWith {_inCombat = true};
	} forEach _aliveUnits;
	//diag_log format["_fn_inCombat::-->> _grp to test is %1 and result is %2",_grp,_inCombat];
	_inCombat;
};

_fn_removeEmptyOrNullGroups = {
	//diag_log format["_fn_removeEmptyOrNullGroups::-->> excuting function at %1",diag_tickTime];
	//  Remove any null groups (which will occur if all units in the group are dead) or groups with no alive AI.
	for "_i" from 0 to ((count blck_monitoredMissionAIGroups) - 1) do
	{
		private["_grp"];
		if (_i >= (count blck_monitoredMissionAIGroups)) exitWith {};
		_grp = blck_monitoredMissionAIGroups select _i;
		if (_grp isEqualTo grpNull) then {
			blck_monitoredMissionAIGroups set[_i, -1]; 
			blck_monitoredMissionAIGroups = blck_monitoredMissionAIGroups - [-1];
			//diag_log "_fnc_waypointMonitor::-->> deleting a NULL-GROUP";
		};
		if ({alive _x} count units _grp < 1) then {
			blck_monitoredMissionAIGroups = blck_monitoredMissionAIGroups - [_grp];
			//diag_log "_fnc_waypointMonitor::-->> deleting an empty group";
		};
	};
};

_fn_monitorGroupWaypoints = {
	{
		private["_timeStamp","_index","_unit","_soldierType"];
		
		_timeStamp = _x getVariable ["timeStamp",0];
		if (_timeStamp isEqualTo 0) then {
			_x setVariable["timeStamp",diag_tickTime];
			//diag_log format["_fn_monitorGroupWaypoints::--> updating timestamp for group %1 at time %2",_x,diag_tickTime];
		};
		_soldierType = _x getVariable["soldierType","null"];
		//diag_log format["_fn_monitorGroupWaypoints::--> soldierType for group %1 = %2 and timeStamp = %3",_x,_soldierType,_timeStamp];
		
		if (_soldierType isEqualTo "infantry") then
		{
			if (diag_tickTime > (_x getVariable "timeStamp") + 60) then
			{
				_units = [_x] call _fn_aliveGroupUnits;
				if (count _units > 0) then
				{
					private _leader = leader _x;
					(_leader) call blck_fnc_changeToMoveWaypoint;
					#ifdef blck_debugMode
					if (blck_debugLevel > 2) then {diag_log format["_fnc_missionGroupMonitor: infantry group %1 stuck, waypoint reset",_x];};
					#endif
					/*
					if ( (getPos _leader) distance2d (_group getVariable "patrolCenter") > 200) then 
					{

					};
					*/
				};

			};
		};
		if (_soldierType isEqualTo "vehicle") then
		{
			if (diag_tickTime > (_x getVariable "timeStamp") + 60) then
			{
				_units = [_x] call _fn_aliveGroupUnits;
				if (count _units > 0) then
				{
					private _leader = leader _x;
					(_leader) call blck_fnc_changeToMoveWaypoint;
					#ifdef blck_debugMode
					if (blck_debugLevel > 2) then {diag_log format["_fnc_missionGroupMonitor: vehicle group %1 stuck, waypoint reset",_x];};
					#endif
					/*
					if ( (getPos _leader) distance2d (_group getVariable "patrolCenter") > 200) then 
					{
					};
					*/
				};

			};
		};
		if (_soldierType isEqualTo "helicopter") then
		{
			if (diag_tickTime > (_x getVariable "timeStamp") + 60) then
			{
				_units = [_x] call _fn_aliveGroupUnits;
				if (count _units > 0) then
				{
					private _leader = leader _x;
					(_leader) call blck_fnc_changeToMoveWaypoint;
					#ifdef blck_debugMode
					if (blck_debugLevel > 2) then {diag_log format["_fnc_missionGroupMonitor: helicopter group %1 stuck, waypoint reset",_x];};
					#endif
					/*
					if ( (getPos _leader) distance2d (_group getVariable "patrolCenter") > 200) then 
					{
						
					};
					*/
				};

			};
		};		
	} forEach blck_monitoredMissionAIGroups;
};

_fn_simulationMonitor = {
	_modType = call blck_fnc_getModType;
	if (_modType isEqualTo "Exile") then
	{
		_playerType = ["Exile_Unit_Player"];
	}else{
		_playerType = ["Epoch_Male_F","Epoch_Female_F"];
	};
	{
		//  player nearEntities [["Car", "Motorcycle", "Tank"], 50];
		_players = (leader _x) nearEntities [_playerType, 1800];
		if (count _players > 0) then
		{
		  // Be sure simulation is on for all units in the group
		  if !(_x getVariable["blck_simulationStatus",false]) then
		  {
			_x setVariable["blck_simulationStatus",true];
			{
				_x enableSimulationGlobal  true;
			}forEach (units _x);
		  };
		}else{
			// Be sure simulation is off for all units in the group.
			if !(_x getVariable["blck_simulationStatus",true]) then
			{
				_x setVariable["blck_simulationStatus",false];
				{
					_x enableSimulationGlobal false;
				}forEach (units _x);		
			};
		};
	} forEach blck_monitoredMissionAIGroups;
};
////////
//  Start of main function
////////
#ifdef blck_debugMode
if (blck_debugLevel > 2) then {diag_log format["_fnc_missionGroupMonitor: executing function at %1",diag_tickTime];};
#endif
[] call _fn_removeEmptyOrNullGroups;
uiSleep 0.1;
[] call _fn_monitorGroupWaypoints;

#ifndef useDynamicSimulation
[] call _fn_simulationMonitor;
#endif
