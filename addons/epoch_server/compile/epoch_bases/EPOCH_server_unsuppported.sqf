/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Building - Unsupported building check (unused ATM)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_unsuppported.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgBaseBuilding","_class","_isSupported","_newObj","_objSlot","_objectPos","_playerUID","_simulClassConfig","_simulatedCount","_slot","_stableCount","_start"];
//[[[end]]]

if !(isNil "EPOCH_unsupportedCheckRunning") exitWith{ diag_log "UnsupportedCheck: Already running aborted"};
EPOCH_unsupportedCheckRunning = true;

_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;

// Check unsupported
_start = diag_tickTime;
_simulatedCount = 0;
_stableCount = 0;
{
	if (!isNull _x) then {
		_simulClassConfig = (_cfgBaseBuilding >> (typeOf _x) >> "simulClass");
		if (isText(_simulClassConfig)) then {
			_objectPos = getPosASL _x;
			_isSupported = isTouchingGround _x;
			if (!_isSupported) then {
				_isSupported = if (terrainIntersectASL[_objectPos, [_objectPos select 0, _objectPos select 1, (_objectPos select 2) - 1]]) then { true } else {
					lineIntersects[_objectPos, [_objectPos select 0, _objectPos select 1, (_objectPos select 2) - 5], _x, objNull]
				};
			};
			if (!_isSupported) then {
				_class = getText(_simulClassConfig);
				_objSlot = _x getVariable["BUILD_SLOT", -1];
				if (_objSlot != -1) then {
					_playerUID = _x getVariable["BUILD_OWNER", "-1"];
					_slot = _x getVariable["EPOCH_secureStorage", "-1"];
					// _newObj = createVehicle[_class, [0,0,0], [], 0, "CAN_COLLIDE"];
					_newObj = [_class,_x] call EPOCH_swapBuilding;
					_newObj setVariable["BUILD_SLOT", _objSlot, true];
					_newObj setVariable["BUILD_OWNER", _playerUID, true];
					_newObj setVariable["EPOCH_secureStorage", _slot];
					_newObj setVelocity[0, 0, -1];
					_simulatedCount = _simulatedCount + 1;
					uiSleep 1;
				};
			} else {
				_stableCount = _stableCount + 1;
			};
		};
	};
} forEach(allMissionObjects "Constructions_static_F");
diag_log format["Epoch: Speed %1 Count %2  Stable %3", (diag_tickTime - _start), _simulatedCount, _stableCount];
EPOCH_unsupportedCheckRunning = nil;
