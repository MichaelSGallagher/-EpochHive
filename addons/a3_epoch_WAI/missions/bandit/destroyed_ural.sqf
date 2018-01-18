/*
	All the code and information provided here is provided under a Commons License.
	http://creativecommons.org/licenses/by-sa/3.0/
	
	Burn Idea from Richie http://epochmod.com/forum/index.php?/topic/34565-dayz-style-heli-crash-sites/
	
*/
if(isServer) then {
	 
	private 		["_rndnum","_burn","_complete","_baserunover","_mission","_directions","_position","_crate","_num","_crate_type","_baserunover0","_baserunover1","_baserunover2","_baserunover3","_baserunover4","_baserunover5","_baserunover6","_baserunover7"];

	// Get mission number, important we do this early
	_mission 		= count wai_mission_data -1;
	waitUntil{!isNil "_mission"};

	_fn_position	= [5] call find_position;
	_position		= _fn_position select 0;
	_missionType	= _fn_position select 0;
	[_mission,_position,"medium","Destroyed Ural","MainBandit",true] call mission_init;
	
	diag_log 		format["WAI: [Mission: Destroyed Ural]: Starting... %1",_position];

	//Setup the crate
	_crate = [2,_position] call wai_spawn_create;
	
	//Destroyed Ural
	_baserunover 	= createVehicle ["Land_Wreck_Ural_F",[((_position select 0) + 10), ((_position select 1) + 10), 0],[],10,"FORM"];
	_burn   = "test_EmptyObjectForFireBig" createVehicle (position _baserunover); 
	_burn  attachto [_baserunover, [0,0,-1]];
	_baserunover 	setVectorUp surfaceNormal position _baserunover;
		
	//Group Spawning
	_rndnum 	= 2 + round (random 3);
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"medium",[1,"AT"],"bandit",_mission] call spawn_group;
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"medium","Random","bandit",_mission] call spawn_group;
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"medium",0,"bandit",_mission] call spawn_group;
	//[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"medium",0,"bandit",_mission] call spawn_group;

	//Condition
	_complete = [
		[_mission,_crate],	// mission number and crate
		["crate"], 			// ["crate"], or ["kill"], or ["assassinate", _unitGroup],
		[_baserunover], 	// cleanup objects
		"Renegades are defending a destroyed Ural! Check your map for the location!",	// mission announcement
		"The supplies have been secured by survivors",		// mission success
		"Survivers did not capture the supplys in time"	// mission fail
	] call mission_winorfail;

	if(_complete) then {
		[_crate,[10,ai_wep_box],[8,crate_items],[15,crate_items_buildables],[4,crate_backpacks_large]] call dynamic_crate;
	};

	diag_log format["WAI: [Mission: Destroyed Ural]: Ended at %1",_position];
	
	b_missionsrunning = b_missionsrunning - 1;
};