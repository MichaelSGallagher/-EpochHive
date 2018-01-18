/*
	All the code and information provided here is provided under a Commons License.
	http://creativecommons.org/licenses/by-sa/3.0/
	
	Communication Center Idea From ZEV Missions Credit to Eugene Zhuravlev
	
	DayZ AI Mission Editor by Eugene Zhuravlev © 2014
	
*/
if(isServer) then {
	 
	private 		["_rndnum","_complete","_baserunover","_mission","_directions","_position","_crate","_num","_crate_type","_baserunover0","_baserunover1","_baserunover2","_baserunover3","_baserunover4"];

	// Get mission number, important we do this early
	_mission 		= count wai_mission_data -1;
	waitUntil{!isNil "_mission"};

	_fn_position	= [20] call find_position;
	_position		= _fn_position select 0;
	_missionType	= _fn_position select 2;
	[_mission,_position,"medium","Communication Center","MainBandit",true] call mission_init;
	
	diag_log 		format["WAI: [Mission: Communication Center]: Starting... %1",_position];

	//Setup the crate
	_crate = [2,_position] call wai_spawn_create;
	
	//Buildings
	_baserunover0 	= createVehicle ["Land_TTowerBig_1_F",[(_position select 0) - 1, (_position select 1),-0.2],[], 0, "CAN_COLLIDE"];
	_baserunover1 	= createVehicle ["Land_Cargo_House_V1_F",[(_position select 0) - 20, (_position select 1),-0.2],[], 0, "CAN_COLLIDE"];
	_baserunover2 	= createVehicle ["Land_Cargo_House_V1_F",[(_position select 0) + 20, (_position select 1),-0.2],[], 0, "CAN_COLLIDE"];
	_baserunover3 	= createVehicle ["Land_Cargo_House_V1_F",[(_position select 0), (_position select 1) - 20,-0.2],[], 0, "CAN_COLLIDE"];
	_baserunover4 	= createVehicle ["Land_Cargo_House_V1_F",[(_position select 0), (_position select 1) + 20,-0.2],[], 0, "CAN_COLLIDE"];
	_baserunover = [_baserunover0,_baserunover1,_baserunover2,_baserunover3,_baserunover4];
	
	_directions = [90,270,90,180,0];
	{ _x setDir (_directions select _forEachIndex) } forEach _baserunover;
	
	{ _x setVectorUp surfaceNormal position _x; } count _baserunover;
	
	//Group Spawning
	_rndnum 	= 2 + round (random 3);
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"medium",[1,"AT"],"bandit",_mission] call spawn_group;
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"medium","Random","bandit",_mission] call spawn_group;
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"medium",0,"bandit",_mission] call spawn_group;
	//[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"medium",0,"bandit",_mission] call spawn_group;

	[[
		[(_position select 0) - 25, (_position select 1) + 25, 0],
		[(_position select 0) + 25, (_position select 1) - 25, 0],
		[(_position select 0) + 25, (_position select 1) + 25, 0],
		[(_position select 0) - 25, (_position select 1) - 25, 0]
	],"O_HMG_01_high_F","medium","bandit",_mission] call spawn_static;

	//Condition
	_complete = [
		[_mission,_crate],	// mission number and crate
		["crate"], 			// ["crate"], or ["kill"], or ["assassinate", _unitGroup],
		[_baserunover], 	// cleanup objects
		"Renegades have setup a Communications Center",	// mission announcement
		"Survivers have captured the Communications Center",		// mission success
		"Survivers did not capture the Communications Center in time"	// mission fail
	] call mission_winorfail;

	if(_complete) then {
		[_crate,[15,ai_wep_box],[8,crate_items],[3,crate_items_high_value],[4,crate_backpacks_large]] call dynamic_crate;
	};

	diag_log format["WAI: [Mission: bandit Communications Center]: Ended at %1",_position];
	
	b_missionsrunning = b_missionsrunning - 1;
};