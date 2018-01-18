/*
  Delete a unit.
  by Ghostrider
  Last updated 1/22/17   
	--------------------------
	License
	--------------------------
	All the code and information provided here is provided under an Attribution Non-Commercial ShareAlike 4.0 Commons License.

	http://creativecommons.org/licenses/by-nc-sa/4.0/
*/
#include "\q\addons\custom_server\Configs\blck_defines.hpp";

private["_ai","_group"];
params["_unit"];

//if (blck_debugLevel > 2) then {diag_log format["_fnc_deleteAI::-> deleting unit = %1",_unit];};

{
	_unit removeAllEventHandlers  _x;
	//_unit removeAllMPEventHandlers _x;
}forEach ["killed","hit","reloaded","fired","handledamage","handleheal","firednear"];
{
	_unit removeAllMPEventHandlers _x;
} forEach ["MPKilled"];
private _group = (group _unit);
[_unit] joinSilent grpNull;
deleteVehicle _unit;
if (count units _group isEqualTo 0) then
{
	deletegroup _group;
};

