/*
	Mission Template by Ghostrider-DbD-
	Mission Compositions by Bill prepared for DBD Clan
	Copyright 2016
	Last modified 3/20/17
	
	--------------------------
	License
	--------------------------
	All the code and information provided here is provided under an Attribution Non-Commercial ShareAlike 4.0 Commons License.

	http://creativecommons.org/licenses/by-nc-sa/4.0/
*/
private ["_markerLabel","_endMsg","_startMsg","_lootCounts","_crateLoot","_markerMissionName","_missionLandscapeMode","_missionLandscape",
	"_missionLootBoxes","_missionLootVehicles","_missionEmplacedWeapons","_minNoAI","_maxNoAI","_noAIGroups","_noVehiclePatrols","_noEmplacedWeapons",
	"_uniforms","_headgear","_chanceReinforcements","_noPara","_helipatrol","_endCondition","_markerColor","_markerType","_useMines"];
//diag_log "[blckeagls] Spawning Orange Mission with template = default";
//diag_log "[blckeagls] Spawning Orange Mission with template = default";
_crateLoot = blck_BoxLoot_Orange;
_lootCounts = blck_lootCountsOrange;
_startMsg = "A group of Bandits was sighted in a nearby sector! Check the Orange marker on your map for the location!";
_endMsg = "The Sector at the Orange Marker is under survivor control!";
_markerLabel = "";
_markerType = ["ELIPSE",[250,250],"GRID"];
_markerColor = "ColorOrange";
_markerMissionName = "Bandit Patrol";
_missionLandscapeMode = "precise"; // acceptable values are "none","random","precise"
_missionLandscape = []; // list of objects to spawn as landscape
_missionLootBoxes = [];  //  Parameters are "Box Item Code", array defining the loot to be spawned, and position.
_missionLootVehicles = []; //  Parameters are "Box Item Code", array defining the loot to be spawned, and position.
_missionEmplacedWeapons = []; // can be used to define the precise placement of static weapons [[1,2,3] /*loc 1*/, [2,3,4] /*loc 2*/]; if blank random locations will be used
//  Change _useMines to true/false below to enable mission-specific settings.
_useMines = blck_useMines;
_minNoAI = blck_MinAI_Orange;
_maxNoAI = blck_MaxAI_Orange;
_noAIGroups = blck_AIGrps_Orange;
_noVehiclePatrols = blck_SpawnVeh_Orange;
_noEmplacedWeapons = blck_SpawnEmplaced_Orange;
_uniforms = blck_SkinList;
_headgear = blck_headgear;
_chanceReinforcements = blck_reinforcementsOrange select 0;
_noPara = blck_reinforcementsOrange select 1;
_helipatrol = blck_reinforcementsOrange select 2;
_endCondition = "playerNear";  // Options are "allUnitsKilled", "playerNear", "allKilledOrPlayerNear"
//_timeOut = -1;
#include "\q\addons\custom_server\Compiles\Missions\GMS_fnc_missionSpawner.sqf"; 
