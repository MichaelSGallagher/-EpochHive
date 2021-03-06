/*
	by Ghostrider [GRG]
	for ghostridergaming
	12/5/17
	--------------------------
	License
	--------------------------
	All the code and information provided here is provided under an Attribution Non-Commercial ShareAlike 4.0 Commons License.

	http://creativecommons.org/licenses/by-nc-sa/4.0/	
*/
#include "\q\addons\custom_server\Configs\blck_defines.hpp";
#define configureWaypoints true
#define isScubaGroup true
// [_pos,_difficulty,_units,_patrolRadius] 
params["_pos",["_skillLevel","red"],["_numUnits",6],["_patrolRadius",15]];
//diag_log format["_fnc_spawnScubaGroup:  _this = %1",_this];
private["_group","_diveDepth"];
_group = grpNull;
// params["_pos", ["_numai1",5], ["_numai2",10], ["_skillLevel","red"], "_center", ["_minDist",20], ["_maxDist",35], ["_uniforms",blck_SkinList], ["_headGear",blck_headgear],["_configureWaypoints",true],["_weaponList",[]],["_vests",blck_vests],["_scuba",false] ];
_group = [_pos,_numUnits,_numUnits,_skillLevel,_pos, _patrolRadius - 2, _patrolRadius, blck_UMS_uniforms, blck_UMS_headgear, configureWaypoints, blck_UMS_weapons, blck_UMS_vests, isScubaGroup] call blck_fnc_spawnGroup;
//diag_log format["_fnc_spawnScubaGroup (14): -> value returned for group = %1",_group];
private _waterDepth = [_pos] call blck_fnc_findWaterDepth;
_diveDepth = _waterDepth * 0.5;
{
	_x swimInDepth (_diveDepth);
} forEach units _group;

#ifdef blck_debugMode
if (blck_debugLevel > 1) then
{
	{
			diag_log format["_fnc_spawnScubaGroup:: _this select %1 = %2",_forEachIndex,_this select _forEachIndex];
	}forEach _this;

	diag_log format["_fnc_spawnScubaGroup:: -->> group spawned = %1",_group];
};
#endif
_group;