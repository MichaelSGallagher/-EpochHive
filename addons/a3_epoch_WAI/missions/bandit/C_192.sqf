/*
	All the code and information provided here is provided under a Commons License.
	http://creativecommons.org/licenses/by-sa/3.0/
	
	Burn Idea from Richie http://epochmod.com/forum/index.php?/topic/34565-dayz-style-heli-crash-sites/
	
*/

if(isServer) then {

	private 		["_rndnum","_burn","_unitGroup","_complete","_vehicle","_rndnum","_crate_type","_crate","_mission","_tanktraps","_mines","_playerPresent","_cleanmission","_currenttime","_starttime","_missiontimeout","_vehname","_veh","_position","_vehclass","_vehdir","_objPosition"];

	// Get mission number, important we do this early
	_mission 		= count wai_mission_data -1;
	waitUntil{!isNil "_mission"};
	
	_fn_position	= [10] call find_position;
	_position		= _fn_position select 0;
	_missionType	= _fn_position select 2;
	
	[_mission,_position,"easy","C-130 Crash","MainBandit",true] call mission_init;

	diag_log 		format["WAI: [Mission: C-130 Crash]: Starting... %1",_position];

	_crate = [2,_position] call wai_spawn_create;
	
	_baserunover 	= createVehicle ["Land_Wreck_Plane_Transport_01_F",[((_position select 0) + 15), ((_position select 1) + 15), 0],[],10,"FORM"];
	_burn   = "test_EmptyObjectForFireBig" createVehicle (position _baserunover); 
	_burn  attachto [_baserunover, [0,0,-1]];
	_baserunover 	setVectorUp surfaceNormal position _baserunover;
	
	// Unit
	_rndnum 	= 4 + round (random 3);
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"Medium","Random","bandit",_mission] call spawn_group;
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"Medium","Random","bandit",_mission] call spawn_group;
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"Medium","Random","bandit",_mission] call spawn_group;
		
	// Condition
	_complete = [
		[_mission,_crate],			// mission number and crate
		["crate"], // ["crate"], or ["kill",wai_kill_percent], or ["assassinate", _unitGroup],
		[_baserunover], 			// cleanup objects
		"A C-130 carrying supplies has crashed and renegades are securing the site! Check your map for the location!",	// mission announcement
		"Survivors have secured the crashed C-130.",											// mission success
		"Survivors did not secure the crashed C-130 in time"							// mission fail
	] call mission_winorfail;
	
	if(_complete) then {
		[_crate,[22,ai_wep_box],[20,crate_items],[3,crate_items_high_value],[4,crate_backpacks_large]] call dynamic_crate;
	};

	diag_log format["WAI: [Mission: C-192 Crash]: Ended at %1",_position];
	
	b_missionsrunning = b_missionsrunning - 1;
};