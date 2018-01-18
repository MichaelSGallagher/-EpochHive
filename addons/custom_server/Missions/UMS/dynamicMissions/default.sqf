/*
	This is a simple mission using precisely placed loot crates and infantry, static weapons and vehicle patrols.
	See the accompanying example mission in the exampleMission folder to get an idea how I laid this out.
	Note that I laid out the mission in EDEN editor, exported the mission using the exportAll function of M3EDEN editor. then copied, pasted and apporpriately edidet the specific categories of items to be spawned.
*/
private ["_markerLabel","_endMsg","_startMsg","_lootCounts","_crateLoot","_markerMissionName","_missionLandscapeMode","_missionLandscape",
	"_missionLootBoxes","_missionLootVehicles","_missionEmplacedWeapons","_minNoAI","_maxNoAI","_noAIGroups","_noVehiclePatrols","_noEmplacedWeapons",
	"_uniforms","_headgear","_chanceReinforcements","_noPara","_helipatrol","_endCondition","_markerColor","_markerType","_useMines","_difficulty","_missionCenter",
	"_missionGroups","_scubaGroupParameters","_vehiclePatrolParameters","_submarinePatrolParameters","_aircraftTypes","_noAirPatrols","_airPatrols"];
params["_missionCenter","_mission"];
//_mission = "UMS mission example #2";  //  Included for additional documentation. Not intended to be spawned as a mission per se.
//_missionCenter = [22584.9,15304.8,0];  // I pulled this from the position of the marker.
_difficulty = "red";  // Skill level of AI (blue, red, green etc)
diag_log format["[blckeagls UMS missions] STARTED initializing dynamic mission %1 position at %2 difficulty %3",_mission,_missionCenter,_difficulty];
_crateLoot = blck_BoxLoot_Orange;  // You can use a customized _crateLoot configuration by defining an array here. It must follow the following format shown for a hypothetical loot array called _customLootArray
	/*
	_customLootArray = 
		// Loot is grouped as [weapons],[magazines],[items] in order to be able to use the correct function to load the item into the crate later on.
		// Each item consist of the following information ["ItemName",minNum, maxNum] where min is the smallest number added and min+max is the largest number added.
		
		[  
			[// Weapons	

				["srifle_DMR_06_olive_F","20Rnd_762x51_Mag"]				
			],
			[//Magazines
				["10Rnd_93x64_DMR_05_Mag" ,1,5]				
			],			
			[  // Optics
				["optic_KHS_tan",1,3]
			],
			[// Materials and supplies				
				["Exile_Item_MetalScrews",3,10]
				//
			],
			[//Items
				["Exile_Item_MountainDupe",1,3]				
			],
			[ // Backpacks
				["B_OutdoorPack_tan",1,2]
			]
	];	
	*/

_lootCounts = blck_lootCountsRed; // You can use a customized set of loot counts or one that is predefined but it must follow the following format:
								  // values are: number of things from the weapons, magazines, optics, materials(cinder etc), items (food etc) and backpacks arrays to add, respectively.
								  //  blck_lootCountsOrange = [[6,8],[24,32],[5,10],[25,35],16,1];   // Orange

_startMsg = "Pirates were spotted off the coast - intercept them and collect the loot";
_endMsg = "The pirates were defeated";
_markerLabel = "";
//_markerType = ["ELIPSE",[200,200],"GRID"];
// An alternative would be:
_markerType = ["mil_triangle",[0,0]];  // You can replace mil_triangle with any other valid Arma 3 marker type https://community.bistudio.com/wiki/cfgMarkers
_markerColor = "ColorRed";  //  This can be any valid Arma Marker Color  
_markerMissionName = "Mafia Fishermen";
_missionLandscapeMode = "precise"; // acceptable values are "random","precise"
									// In precise mode objects will be spawned at the relative positions specified.
									// In the random mode, objects will be randomly spawned within the mission area.
_missionLandscape = [  //  Paste appropriate lines from M3EDEN output here.
	//  ["Land_Cargo_HQ_V2_F",[22894.7,16766,3.19],[[0,1,0],[0,0,1]],[true,false]],
	["Land_Boat_05_wreck_F",[1,1,0],0,[true,false]]
]; // list of objects to spawn as landscape using output from M3EDEN editor.

_missionLootBoxes = [  //  Paste appropriate lines from M3EDEN editor output here, then add the appropriate lootArray
	// [["box_classname1",_customLootArray1,[px,py,pz],...,_customLootArray1],["box_classname2",,[px2,py2,pz2],...,_customLootArray2]
	//  where _customLootArray follows the same format as blck_BoxLoot_Red and the other pre-defined arrays and
	//  where _customlootcountsarray1 also follows the same format as the predefined arrays like blck_lootCountsRed
		//  ["Box_NATO_Ammo_F",[22893,16766.8,6.31652],[[0,1,0],[0,0,1]],[true,false], _crateLoot, _lootCounts],
		//["Exile_Container_SupplyBox",[1.91016,-3.85352,-3.54709],0,[true,false], _crateLoot, _lootCounts]
		[selectRandom blck_UMS_crates,[0,0,0],_crateLoot, _lootCounts]
];  // If this array is empty a single loot chest will be added at the center. If you add items loot chest(s) will be spawned in specific positions.



_missionLootVehicles = [  // Paste appropriate lines from the output of M3EDEN Editor here and add the loot crate type and loot counts at the end of each entry as shown in the example below.
						  // Many vehicles have less inventory capacity than crates so you may have to modify _lootcounts to avoid having stuff spawned all over the ground.
	//["Exile_Car_Van_Box_Guerilla02",[22896.8,16790.1,3.18987],[[0,1,0],[0,0,1]],[true,false], _crateLoot, [[1,2],[4,6],[2,6],[5,8],6,1]],
	["I_Boat_Transport_01_F",[3,3,0],_crateLoot, _lootCounts]
]; //  [ ["vehicleClassName", [px, py, pz] /* possition at which to spawn*/, _loot /* pointer to array of loot (see below)]; 
// When blank nothing is spawned.
// You can use the same format used for _missionLootBoxes to add vehicles with/without loot.
							
_minNoAI = 3;  //  Modify as needed
_maxNoAI = 4;	// Modify as needed.
_noAIGroups = 1;  // Modify as needed; note that these values are ignored of you specify AI patrols in the array below.
_missionGroups = 
[
	// position relative to center, difficulty, no AI, minRadius, maxRadius
	// [[1,-1,-1],"red",4, 5,10]
];
_scubaGroupParameters = [
	// [ [px, py, pz] /* position*/, "difficulty", 4 /*Number to Spawn*/, 5,10 /* min/max radius of patrol*/]
	[[-1,1,-1],"red",4, 5,10],
	[[1,-1,-1],"red",4, 5,10]
];

//_noVehiclePatrols = blck_SpawnVeh_Red; // Not useful for marine missions which we assume need pre-defined positions for vehicles.
// These are surface patrols. 
_vehiclePatrolParameters = [
	//  	["B_MRAP_01_hmg_F",[27.8945,100.275,0],0,[true,false]],
	["B_T_Boat_Armed_01_minigun_F",[1.21094,1.01465,0],0]
	//["B_T_Boat_Transport_01_F",[16.7676,43.083,-0.00134277],"red",4, 75,60]	
]; 							//[ ["vehicleClassName",[px,py,pz] /* center of patrol area */, difficulty /* blue, red etc*/, patrol radius] ]
							// When this array is empty, vehicle patrols will be scattered randomely around the mission.
							// Allows you to define the location of the center of the patrol, vehicle type spawned, radius to patrol, and AI difficulty (blue, red, green etc).

_submarinePatrolParameters = [
	//  
	//["B_SDV_01_F",[22584.9,15304.8,-6.14801],"red",4, 75,0],
	["B_SDV_01_F",[-1.0215,-1.4219,-1.5],0]
];

_missionemplacedweapons = [

];

_aircraftTypes = blck_patrolHelisRed;  //  You can use one of the pre-defined lists in blck_configs or your own custom array.
_noAirPatrols =	blck_noPatrolHelisRed; // You can use one of the pre-defined values or a custom one. acceptable values are integers (1,2,3) or a range such as [2,4]; 
										//  Note: this value is ignored if you specify air patrols in the array below.
_airPatrols = [
	[selectRandom blck_patrolHelisRed,[0,0,10],0]
];
//  Change _useMines to true/false below to enable mission-specific settings.
_useMines = false;  // Set to false if you have vehicles patrolling nearby.
_useMines = blck_useMines;
/* 
	The values below are here as placeholders.
	I recommend that you use the arrays above to define approximate number and spawn location of all AI units.
*/
_minNoAI = blck_MinAI_Blue;
_maxNoAI = blck_MaxAI_Blue;
_noAIGroups = blck_AIGrps_Blue;
_noVehiclePatrols = blck_SpawnVeh_Blue;
_noEmplacedWeapons = blck_SpawnEmplaced_Blue;
// Pertains to AI on boats, structures or land
// The UMS configurations are used for sub and scuba AI.
// These are defined here because they are needed for any calls used to spawn non-scuba AI
_uniforms = blck_SkinList;
_headgear = blck_headgear;
_endCondition = "playerNear";
diag_log "[blckeagls] initialized variables for dynamic UMS mission default.sqf";
diag_log format["[blckeagls static missions] COMPLETED initializing mission %1 position at %2 difficulty %3",_mission,_missionCenter,_difficulty];
#include "\q\addons\custom_server\Missions\UMS\code\GMS_fnc_spawnDynamicUMSMission.sqf"; 

