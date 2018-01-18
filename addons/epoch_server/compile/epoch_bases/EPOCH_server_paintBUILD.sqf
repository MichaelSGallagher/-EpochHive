/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Building Paint handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_paintBUILD.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgBaseBuilding","_class","_color","_currentTextureSlot","_objSlot","_playerUID"];
//[[[end]]]
params [["_object",objNull],"_textureSlot","_player",["_token","",[""]] ];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _object) exitWith{};
if (_player distance _object > 20) exitWith{};

_playerUID = getPlayerUID _player;

_objSlot = _object getVariable["BUILD_SLOT", -1];
if (_objSlot != -1) then {

	_currentTextureSlot = _object getVariable["TEXTURE_SLOT", 0];
	if (_textureSlot != _currentTextureSlot) then {

		_class = typeOf _object;
		_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
		_color = getArray(_cfgBaseBuilding >> _class >> "availableTextures");
		if !(_color isEqualTo[]) then {
			_object setObjectTextureGlobal[0, (_color select _textureSlot)];
			_object setVariable["TEXTURE_SLOT", _textureSlot, true];
			_object call EPOCH_saveBuilding;
		};
	};
};
