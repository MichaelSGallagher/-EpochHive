/*
	Run scripts exported from M3EDEN Editor plug in for Arma 3 or other map addons. 
	Add addons to the arrays for Epoch or Exile as appropriate.
	Arrays should contain ["mapname", "name of folder within mapaddons","name of file to execute"]
	by Ghostrider-DbD-
	for DBD Clan
	11/12/16
	--------------------------
	License
	--------------------------
	All the code and information provided here is provided under an Attribution Non-Commercial ShareAlike 4.0 Commons License.

	http://creativecommons.org/licenses/by-nc-sa/4.0/	
*/

#include "\q\addons\custom_server\Configs\blck_defines.hpp";


params["_coords","_noVehiclePatrols","_vehiclePatrolSpawns","_aiDifficultyLevel","_uniforms","_headGear",["_missionType","unspecified"]];
diag_log format["_sm_spawnVehiclePatrols:: _vehiclePatrolSpawns = %1",_vehiclePatrolSpawns];
private["_vehGroup","_patrolVehicle","_missionAI","_missiongroups","_vehicles","_return","_vehiclePatrolSpawns","_randomVehicle","_return","_abort"];

if (_vehiclePatrolSpawns isEqualTo []) then
{
	private["_spawnPoints","_vehType"];
	_spawnPoints = [_coords,_noVehiclePatrols,75,100] call blck_fnc_findPositionsAlongARadius;
	{
	  //  ["B_G_Offroad_01_armed_F",[22819.4,16929.5,3.17413],"red", 600],
	  _vehType = selectRandom blck_AIPatrolVehicles;
	  _vehiclePatrolSpawns pushBack [_vehType, _x, _aiDifficultyLevel, 150];
	} forEach _spawnPoints;
};

{
	private ["_vehicle","_spawnPos","_difficulty","_patrolRadius"];
	_vehicle = _x select 0;
	_spawnPos = _x select 1;
	_difficulty = _x select 2;
	_patrolRadius = _x select 3;
	_vehGroup = [_spawnPos,3,3,_difficulty,_spawnPos,1,2,_uniforms,_headGear,false] call blck_fnc_spawnGroup;

	//params["_center","_pos",["_vehType","I_G_Offroad_01_armed_F"],["_minDis",30],["_maxDis",45],["_group",grpNull]];
	_patrolVehicle = [_spawnPos,_spawnPos,_vehicle,_patrolRadius,_patrolRadius,_vehGroup] call blck_fnc_spawnVehiclePatrol;
	_vehGroup setVariable["groupVehicle",_vehicle];

	if !(isNull _patrolVehicle) then
	{
		_patrolVehicle setVariable["vehicleGroup",_vehGroup];
	};
} forEach _vehiclePatrolSpawns;

true


