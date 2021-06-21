# TestingGroundsFPS

This is the last course session to Udemy Unreal Course.
---

## 1 First Commit ##

The first commit is to align with the course ep.
---

## 2 GDD (Game Description Document) ##
### Description
* 2.1 You can pass a testing ground undetected
* 2.2 If detected, you must clear the area
* 2.3 Checkpoints save when you pass to a new area
* 2.4 If killed you return to the last checkpoint
* 2.5 You and enemies fight for same ammo reosources
* 2.6 You are scored on how many areas you can pass
### Requirement
* 2.7 Testing ground landscape(s)
* 2.8 Unreal starter content + landscape tools
* 2.9 2 guns, and 2 ammo box types
* 2.10 A rigged humanoid character we can modify
* 2.11 Various SFX
* 2.12 Other stuff
### Challenge
* 2.13 Serialization when saving
* 2.14 Checkpoint system architecture
* 2.15 Smooth network for co-op play
* 2.16 Procedural generation of testing grounds
* 2.17 Creating a new skeletal animation
---

## 3 Markdown & Market Decoration ##
* HASH "#" stands for title
* START "*" stands for item
* DASH "---" stands for line break
---

## 4 Git clean -x -d -i ##

+ Using git clean -x -d -i in terminal can clean the files in gitignore to avoid any impact when doing the code reverse.
---

## 5 Target Points ##

+ Target point array is to assign an agent to patrol around these target locations.
+ By implementing these target points, AI behaviour tree and blackboard are often used.
---

## 6 Assets Grouping ##

+ Layers are often for visibility. One assets can be assigned to multiple layers.
+ Groups are often for batch operation and fast multi selection.
+ Tags are ... not sure what are the advantages... probably for tracking in the CPP???
+ Parent Empty Actors are often for iterating the children and for batch moving.
+ Folders are often to organize the hierachy.
---

## 7 Behavior Tree ##

+ Behavior tree is using a sequence module to switch the index cycle and the move to action. Index cycle is made in blueprint.
---

## 8 Performance Profiling ##

+ Using blueprint can drag system running slow. In order to check the load/consume of each function/method in the blueprint/cpp. Performance profiling is a good way. 
+ Window -> Developer Tools -> Frontend Session.
---

## 9 EditInstanceOnly vs EditAnywhere vs EditDefaultsOnly ##

+ EditAntwhere means the variable can be modified either in the blueprint, or in the instance generated (inherited) by the blueprint.
+ EditDefaultsOnly means the variable can be only modified in the blueprint.
+ EditInstanceOnly means the variable can be only modified in the instance generated.
---

## 10 Graphs in an animation blueprint ##

+ EventGraph is much like the other event graghs in the blueprint where the variables are mostly set up here.
+ AnimGraph is to set which animation should be applied to the skeleton. State machine can be used to switch in between different states.
---

## 11 About Blackboard ##

+ Blackboard is like a dictionary where a "key-value" combo is always set.
+ When you need to SET a blackboard value, you always need to "Set value as xxx", and assign it with a key and their true value.
+ When you need to GET a blackboard value, you alwasy need to "Get value as xxx", and feed it with a key name and the value would return accordingly.
+ When dealing with a behavior tree at the same time, the key to the SETTER and the GETTER can be different as usually a BTtask would be created.
+ Therefore, the SETTER key (KEY_SETTER) and the GETTER key (KEY_GETTER) would be matached at the BTtask assign interface.
---

## 12 Map out the source codes ##

+ TODO map out how the NPC is sharing same movement component (especially rotation) with the human player.
---

## 13 SetFocus ##

+ Compared with SetFocusPoint, SetFoucs has more ability where an actor can be used as a target "point".
+ Pitch angle will also be used to SetFocus.
+ However, please do remember to tick Pawn->Use Controller Rotation Pitch / Yaw and Roll!
+ The aiming point seems to be the actor bottom point.
---

## 14 Services ##

+ If you want to do something repeatly, use service.
---

## 15 lfs and git ##

+ Change track file: .gitattibutes
+ Fresh lfs cache (to make files untracked from LFS): git rm --cached -r "PATH/."
+ Re-add lfs files: git -add "PATH/."
---

## 16 IK ##

---

## 17 Extract old version blueprint ##

+ $ git show "SHORT_ID":"PATH" | git lfs smudge > "PATH" (to generate the old blueprint)
--- 

## 18 Animation slot ##

+ Animation slot is a placeholder to feed in the animations. (to make 1 mesh listens to 2 parts: animation slot overrides the states machine)
+ Layer blend per bone is a good way to seperate the bone animation in the structure where it can makes the upper body running 1 animation with the lower body not impacted.
---

## 19 Github Pull & Push test ##

No other aims. Just for testing. ver2.
---







