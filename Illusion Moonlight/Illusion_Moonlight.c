//===== Crazyarashi Services =====================================|
//= Illusion Dungeon : Moonlight                                 =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

pay_d03_i	mapflag	nomemo
pay_d03_i	mapflag	nosave
pay_d03_i	mapflag	nobranch
pay_d03_i	mapflag	noicewall

payon,164,229,5	script	Elder Sanryu#illusion_moonlight	1_F_ORIENT_04,{
	if(BaseLevel < 100){
		mes "[ Sanryu ]";
		mes "Mm, I have a feeling something suspicious is about to happen.";
		mes "I wish you were stronger. Then, I would've been able to tell you about it.";
		next;
		mes "^4D4DFFYou must be Level 100 or above to perform this quest.^000000";
		close;
	}
	if(illusion_moonlight == 0){
	OnStart:
		mes "[ Jagyeom ]";
		mes "This matter is out of our hands now.";
		mes "We can't let it keep happening like this.";
		next;
		mes "[ Sanryu ]";
		mes "Let's wait for ^0000FFMuyeon^000000 now.";
		mes "Her safety is more important than anything else.";
		next;
		if(select("Excuse me."))
		mes "[ Sanryu ]";
		mes "Hm? You're an adventurer.";
		mes "Did you happen to hear our conversation?";
		next;
		mes "[ Sanryu ]";
		mes "I see.";
		mes "Maybe it's faith that you overheard us.";
		next;
		mes "[ Sanryu ]";
		mes "There's a cave near the Archer Village in the back of Payon.";
		mes "It's a haunted cave, so we've been preforming rituals and exorcism there regularly.";
		next;
		mes "[ Sanryu ]";
		mes "But the Nine-tailed foxes spirits are more enraged than we thought.";
		mes "Every time someone tries to preform a ritual to the fox beads, they get nightmares.";
		npctalk "It's as if the spirits were antagonized by them.","Elder Jagyeom#illusion_moonlight",bc_self;
		next;
		mes "[ Sanryu ]";
		mes "And this time, she's completely lost her mind and entered the cave.";
		mes "That's why we're worried about her.";
		next;
		if(select("Is it about Muyeon?"))
		npctalk "Maybe we should send someone else.","Elder Jagyeom#illusion_moonlight",bc_self;
		mes "[ Sanryu ]";
		mes "Yes. She's the Soul Linker who performs the ritual regularly.";
		mes "We've asked a soldier to find her.";
		mes "They must be near the cave by now.";
		next;
		mes "[ Jagyeom ]";
		mes "Could you go check up ^0000FFMuyeon^000000 for us?";
		next;
		npctalk "Yes. could you?","",bc_self;
		if(select("Sure, I will:Sorry, I'm afraid of ghost.") == 2){
			mes "[ Sanryu ]";
			mes "Huh? We didn't say anything about ghost. Or did we?";
			close;
		}
		mes "[ Jagyeom ]";
		mes "I hope the soldier will find her before she goes deep inside the ruined village.";
		next;
		mes "[ Jagyeom ]";
		mes "Please go to the cave and see if Muyeon and the soldier are outside already.";
		mes "A young scholar followed the soldier, but she doesn't seem reliable at all.";
		next;
		mes "[ Jagyeom ]";
		mes "Talk to the scholar, maybe he could give you an information on the situation.";
		setquest 7776;
		illusion_moonlight = 1;
		end;		
	}
	if(illusion_moonlight == 1){
		mes "[ Jagyeom ]";
		mes "I hope the soldier will find her before she goes deep inside the ruined village.";
		next;
		mes "[ Jagyeom ]";
		mes "Please go to the cave and see if Muyeon and the soldier are outside already.";
		mes "A young scholar followed the soldier, but she doesn't seem reliable at all.";
		next;
		mes "[ Jagyeom ]";
		mes "Talk to the scholar, maybe he could give you an information on the situation.";
		close;
	}
	mes "[ Sanryu ]";
	mes "I hope everything will be okay.";
	mes "Huh? I was talking about the cave in the back.";
	mes "I'm worried about what's happening there.";
	close;

OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"BaseLevel >= 100 && illusion_moonlight < 1";
end;	
}

payon,167,229,3	script	Elder Jagyeom#illusion_moonlight	4_M_HUOLDARMY,{
	if(BaseLevel < 100){
		mes "[ Jagyeom ]";
		mes "I hope everything will be okay.";
		mes "Seeing that you're an adventurer, I assume you're familiar with the ^0000FFPayon Cave^000000.";
		mes "Be careful, something bad is happening inside.";
		next;
		mes "^0000FFYou must be Level 100 or above to perform this quest.";
		close;
	}
	if(illusion_moonlight == 0){
		doevent "Elder Sanryu#illusion_moonlight::OnStart";
		end;
	}
	if(illusion_moonlight == 1){
		mes "[ Sanryu ]";
		mes "Please go to the cave's entrance in the Archer Village.";
		mes "Ask the young scholar there about Muyeon's whereabouts.";
		close;
	}
	mes "[ Jagyeom ]";
	mes "Maybe it's time we leave things to the younger generations.";
	mes "There is nothing we old folk could do.";
	close;		
}

pay_arche,48,137,4	script	Young Scholar#ill_moon_arch	4_F_03,{
	if(illusion_moonlight == 0){
		npctalk "Why aren't they coming out already...","",bc_self;
		end;
	}
	if(illusion_moonlight == 1){
		npctalk "Why are they still not coming out...","",bc_self;
		mes "[ Young Scholar ]";
		mes "Ah, today must be my lucky day!","An adventurer showed up, just when I needed one!";
		next;
		mes "[ Young Scholar ]";
		mes "Excuse me.","I've heard adventurers do many things for others. Is that true?";
		next;
		select("It is, but I'm pretty busy for now.:Decline.");
		mes "[ Young Scholar ]";
		mes "...Oh, I see.","You must be busy.","I'm sorry I bothered you.","By the way, what brings you here?";
		next;
		select("Have you seen someone named Muyeon?");
		mes "[ Young Scholar ]";
		mes "Muyeon? Do you mean Muyeon the Soul Linker?","Well, technically, she's still an apprentice, but that's not important.";
		next;
		mes "[ Young Scholar ]";
		mes "I'm waiting for her right now.","She ran into the cave, as if she was possessed by something.";
		next;
		mes "[ Young Scholar ]";
		mes "Junghee? I mean, a soldier followed her in, but neither of them came out yet.","I was debating if I should go after them.";
		next;
		mes "[ Young Scholar ]";
		mes "I hope nothing bad happens to those two.";
		cloaknpc("Payon Soldier#ill_moon_arch",false,getcharid(0));
		cloaknpc("Muyeon#ill_moon_arch",false,getcharid(0));
		sleep2 750;
		npctalk "There they are! They look fine!","Young Scholar#ill_moon_arch",bc_self;
		sleep2 1500;
		npctalk "Ugh, I don't want to train anymore!","Muyeon#ill_moon_arch",bc_self;
		npctalk "...","Payon Soldier#ill_moon_arch",bc_self;
		next;
		mes "[ Muyeon ]";
		mes "Chunghae, what are you doing out here?";
		npctalk "I was worried about you..","",bc_self;
		next;
		mes "[ Muyeon ]";
		mes "You were worried about me, but this is as far you were willing to follow me?","Forget it. No matter how miserable I am, I don't need your help!";
		sleep2 500;
		npctalk "Now, that's enough.","Payon Soldier#ill_moon_arch",bc_self;
		sleep2 500;
		npctalk "Th-this is unfair...","",bc_self;
		next;
		npctalk "Bye!","Muyeon#ill_moon_arch",bc_self;
		mes "[ Muyeon ]";
		mes "Ah, I'm not going to do this anymore. Tell that to the old geezers!";
		next;
		npctalk "Sigh. I'll go after her. Talk to the Elders, will you?","Payon Soldier#ill_moon_arch",bc_self;
		sleep2 1500;
		cloaknpc("Payon Soldier#ill_moon_arch",true,getcharid(0));
		cloaknpc("Muyeon#ill_moon_arch",true,getcharid(0));
		mes "[ Young Scholar ]";
		mes "That's....!","She left without telling us what happened.";
		next;
		mes "[ Young Scholar ]";
		mes "Ah, Junghee!","By the way adventurer, weren't you looking for Muyeon?";
		next;
		select("I guess I have to leave now.");
		mes "[ Young Scholar ]";
		mes "Muyeon must have gone to the ^0000CDDetached Payon Palace.^000000","I'm going there do you want to come with me?";
		next;
		illusion_moonlight = 2;
		completequest 7776;
		setquest 7777;
        if(select("Go with him.:Go separately.") == 2){  
			mes "[ Young Scholar ]";
			mes "Muyeon must have gone to the ^0000CDDetached Payon Palace.^000000","Why don't you go talk to her?","I'll talk to the Elders.";
			end;
        }
		mes "[ Young Scholar ]";
		mes "Then let's go to the ^0000CDDetached Payon Palace.^000000";
        close2;
        warp "payon",105,320;
        end;
	}
	if(illusion_moonlight == 2){
		mes "[ Young Scholar ]";
		mes "Muyeon must have gone to the ^0000CDDetached Payon Palace.^000000","Why don't you go talk to her?","I'll talk to the Elders.";
		close;
	}
	if(illusion_moonlight < 6){
		mes "[ Young Scholar ]";
		mes "Legend says a nine-tailed fox gained enlightment and became a sacred creature, and that Moonlight Flowers have descended from her.  I think it's a story worth looking into.";
		close;
	}
	mes "[ Young Scholar ]";
	mes "Let's go investigate the ruined village!","Would you like to come with me?";
	next;
	if(select("Go with him.:Go separately.") == 2){
		mes "[ Young Scholar ]";
		mes "I'll call Junghee, and we'll follow you soon.";
		close;
	}
	mes "[ Young Scholar ]";
	mes "Let's go!";
	close2;
	warp "pay_dun03",145,43;
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 1";
end;
}

pay_arche,44,133,7	duplicate(dummynpc)	Payon Soldier#ill_moon_arch	4_M_PAY_SOLDIER
pay_arche,46,135,5	duplicate(dummynpc)	Muyeon#ill_moon_arch	4_F_TAEKWON

payon_in03,33,95,3	script	Muyeon#ill_moon_pin	4_F_TAEKWON,{
	if(checkweight(25271,1) == 0 || (MaxWeight - Weight) < 1000){
		mes "- You're carrying too many items to proceed with this quest. -";
		close;
	}
	if(illusion_moonlight < 2){
		mes "[ Muyeon ]";
		mes "If you're looking for the teacher, she's in the other room.";
		close;
	}
	if(illusion_moonlight == 2){
		.@elder$ = "Jagyeom#ill_moon_pin";
		.@scholar$ = "Young Scholar#ill_moon_pin";
		setpcblock PCBLOCK_ALL,true;
		npctalk "Whatever you say, I'm not doing it anymore.","",bc_self;
		sleep2 2500;
		npctalk "This is the third time I had nightmares. I can't take it anymore!","",bc_self;
		sleep2 1000;
		unittalk getcharid(3),"What nightmares?",bc_self;
		npctalk "What nightmares?",.@scholar$,bc_self;
		sleep2 2000;
		npctalk "Nightmares about about the foxes? Nine tails and Moonlight flowers?","",bc_self;
		sleep2 2000;
		npctalk "Those nightmares are just too horrifying. I don't want to experience it anymore.","",bc_self;
		sleep2 2000;
		npctalk "But we have no one else left to perform the ritual.",.@elder$,bc_self;
		sleep2 2000;
		npctalk "Everyone gave up after the first try. You did it three times.",.@elder$,bc_self;
		sleep2 2000;
		npctalk "Elder Jaegyom, nightmares weren't the only thing occurred to me this time.","",bc_self;
		sleep2 2000;
		npctalk "It was different from the other two times I performed the ritual.","",bc_self;
		sleep2 2000;
		npctalk "How different?",.@scholar$,bc_self;
		sleep2 2000;
		npctalk "...","",bc_self;
		sleep2 2000;
		npctalk "It felt as if the nightmares is happening in reality.","",bc_self;
		sleep2 2000;
		npctalk "What do you mean? You were only trying to give peace to the angered spirits of the nine tailed foxes.",.@elder$,bc_self;
		sleep2 2000;
		npctalk "What did you see in the cave?",.@elder$,bc_self;
		sleep2 2000;
		npctalk "I can't explain what I saw. You have to see it to believe it.","",bc_self;
		sleep2 2000;
		npctalk "We need someone strong to go in there, like that adventurer over there, should go in the cave.","",bc_self;
		illusion_moonlight = 3;
		completequest 7777;
		setquest 7778;
		setpcblock PCBLOCK_ALL,false;
		end;
	}
	if(illusion_moonlight == 3){
		mes "[ Muyeon ]";
		mes "Okay, I'll tell you the story.";
		mes "The Payon Cave is used to be a part of a village that was buried under a landslide.";
		next;
		mes "[ Muyeon ]";
		mes "As you can guess many people were buried with it, and their spirits are hunting the cave.";
		next;
		mes "[ Muyeon ]";
		mes "Some of them were the nine-tailed foxes. The foxes anger is beyond normal.";
		mes "That's the reason we have been performing a ritual in regular basis.";
		next;
		mes "[ Muyeon ]";
		mes "But now the problem is,";
		mes "The foxes spirits are getting more resentful by time, and no one knows the reason why.";
		mes "Maybe the ritual is the reason they are angry, it's not working as we hoped it would.";
		next;
		mes "[ Muyeon ]";
		mes "And, every time I performed the ritual, I had nightmares about the resentful spirits and wailing nine-tailed foxes.";
		next;
		mes "[ Muyeon ]";
		mes "Soul Linkers communicates with the spirits for a living, Having nightmares is just occurs normally.";
		next;
		mes "[ Muyeon ]";
		mes "So when my first nightmare occurred, I thought it was under the same boat as the others.";
		mes "But now I know the difference, It also has nothing to do with my health.";
		next;
		mes "[ Muyeon ]";
		mes "Whatever it is the reason that agitates the spirits of the nine-tailed foxes.";
		mes "It drove me from sanity and sent me going to the ruined village.";
		next;
		mes "[ Muyeon ]";
		mes "And, I saw something.";
		mes "It's an image of another world, different from ours.";
		mes "We must shut that place down, so no one will be able to access it.";
		next;
		mes "[ Muyeon ]";
		mes "I have an uneasy feeling that a dreadful is going to take place.";
		mes "Or maybe it's already taking place..";
		next;
		mes "[ Muyeon ]";
		mes "The vague image I saw is indistinguishable from hell.";
		mes "I saw it after the last ritual that I did.";
		next;
		mes "[ Muyeon ]";
		mes "I beg of you, don't ask me to return doing that again.";
		mes "I'm not mentally strong enough to handle such nightmares.";
		next;
		mes "[ Muyeon ]";
		mes "Much less on what's taking place inside the cave.";
		next;
		mes "[ Muyeon ]";
		mes "If you want to go, you'll have to go alone and see it for yourself.";
		mes "I still carry the fox bead that I tried to purify. Let me know when you are ready.";
		illusion_moonlight = 4;
		completequest 7778;
		setquest 7779;
		end;
	}
	if(illusion_moonlight == 4){
		mes "[ Muyeon ]";
		mes "Are you ready?";
		next;
		if(select("Yes.:Not yet.") == 2){
			mes "[ Muyeon ]";
			mes "Let me know when you're ready.";
			close;
		}
		mes "[ Muyeon ]";
		mes "Okay, this fox bead is not completely purged yet.","Place it in your hand.";
		next;
		mes "[ Muyeon ]";
		mes "Relax... and focus your mind on it ... open your mind to its energy.";
		close2;
		setpcblock PCBLOCK_ALL,true;
		npctalk "Wandering souls, listen and behold!","",bc_self;
		sleep2 250;
		specialeffect EF_PORTAL4;
		specialeffect EF_GROUNDSAMPLE;
		sleep2 1800;
		npctalk "Look at the other side of the Netherworld River.","",bc_self;
		sleep2 250;
		specialeffect EF_PORTAL5;
		specialeffect EF_QUAKEBODY2;
		for(.@i = 0; .@i < 4; .@i++){
			cloaknpc("Nine Tail Spirit#ill_moon_" + .@i,false,getcharid(0));
			specialeffect EF_REDBODY,AREA,"Nine Tail Spirit#ill_moon_" + .@i;
			specialeffect EF_QUAKEBODY2,AREA,"Nine Tail Spirit#ill_moon_" + .@i;
			sleep2 250;
		}
		sleep2 1500;
		npctalk "Poor souls, cover your eyes and block your ears.","",bc_self;
		sleep2 150;
		specialeffect2 EF_DEVIL1;
		for(.@i = 0; .@i < 4; .@i++){
			specialeffect EF_QUAKEBODY2,AREA,"Nine Tail Spirit#ill_moon_" + .@i;
			sleep2 30;
		}
		npctalk "Die!","Nine Tail Spirit#ill_moon_0",bc_self;
		sleep2 100;
		specialeffect2 EF_DEVIL6;
		sleep2 100;
		for(.@i = 0; .@i < 4; .@i++){
			specialeffect EF_QUAKEBODY2,AREA,"Nine Tail Spirit#ill_moon_" + .@i;
			sleep2 30;
		}
		sleep2 150;
		npctalk "Die!","Nine Tail Spirit#ill_moon_1",bc_self;
		sleep2 1000;
		npctalk "Leave this realm.","",bc_self;
		sleep2 150;
		specialeffect2 EF_DEVIL10;
		for(.@i = 0; .@i < 4; .@i++){
			specialeffect EF_QUAKEBODY2,AREA,"Nine Tail Spirit#ill_moon_" + .@i;
			sleep2 30;
		}		
		npctalk "Die!","Nine Tail Spirit#ill_moon_2",bc_self;
		sleep2 150;
		specialeffect EF_BLUELINE;
		sleep2 150;
		npctalk "Die!","Nine Tail Spirit#ill_moon_3",bc_self;
		sleep2 700;
		npctalk "Unload your burden.","",bc_self;
		sleep2 150;
		for(.@i = 0; .@i < 4; .@i++){
			specialeffect EF_MAP_GHOST,AREA,"Nine Tail Spirit#ill_moon_" + .@i;
			sleep2 30;
		}
		for(.@i = 0; .@i < 4; .@i++)
			npctalk "DIE!!!","Nine Tail Spirit#ill_moon_" + .@i,bc_self;
		sleep2 1200;
		specialeffect EF_BLUELINE;
		sleep2 500;
		specialeffect EF_SCREEN_QUAKE;
		sleep2 1200;
		npctalk "Fly to the other side of the river.","",bc_self;
		for(.@i = 0; .@i < 4; .@i++){
			specialeffect EF_MADNESS_RED,AREA,"Nine Tail Spirit#ill_moon_" + .@i;
			sleep2 30;
		}
		for(.@i = 0; .@i < 4; .@i++){
			npctalk "DIEEE!", "Nine Tail Spirit#ill_moon_" + .@i, bc_self;
			sleep2 50;
			specialeffect EF_SCREEN_QUAKE;
			sleep2 300;
		}
		sleep2 1000;
		for(.@i = 0; .@i < 4; .@i++){
			npctalk "DIEEE!", "Nine Tail Spirit#ill_moon_" + .@i, bc_self;
			sleep2 100;
		}
		specialeffect2 EF_JUMPBODY1;
		sleep2 150;
		completequest 7779;
		setquest 7780;
		illusion_moonlight = 5;
		setpcblock PCBLOCK_ALL,false;
		warp "pay_dun03",145,43;
		end;
	}
	if(illusion_moonlight == 5){
		mes "[ Muyeon ]";
		mes "Now you know what I've been through.","If you want to look further into this, you'll have to visit the ruined village.";
		next;
		mes "[ Muyeon ]";
		mes "If you decide to do it, it'll make you one of us, very ecstatic. Probably because he is a fool.";
		close;
	}
	if(illusion_moonlight < 8){
		mes "[ Muyeon ]";
		mes "If you're looking for the teacher, she's in the other room.";
		close;
	}
	if(illusion_moonlight == 8){
		mes "[ Muyeon ]";
		mes "I see.","So They've come true.","You don't know why, do you?";
		next;
		mes "[ Muyeon ]";
		mes "Maybe it's because the walls between reality and dreams have collapsed.","Otherwise, how could you go in and out of someone else's dream?";
		next;
		mes "[ Muyeon ]";
		mes "I know they're ^0000FFdreamt by the Moonlight Flowers.^000000","I don't know how they've become reality. I doubt anyone knows, really.";
		next;
		mes "[ Muyeon ]";
		mes "As far as I remember, nothing like this has ever happened before. If we want to figure this out, we're on our own.";
		next;
		mes "[ Muyeon ]";
		mes "Well, I'll let Chunghae figure it out.","Alright, then I'd better go get some rest.";
		next;
		mes "[ Muyeon ]";
		mes "Now that I know that those nightmares really originated from Moonlight Flowers, I feel better.","I can sleep at last.";
		next;
		mes "[ Muyeon ]";
		mes "We won't need more rituals once we deal with the nightmares.","Does this mean I'm free? Free at last!","I don't even know how to thank you.";
		next;
		mes "[ Muyeon ]";
		mes "I've found this strange stones while I was there. It's not much,";
		mes "but maybe you can find an use for those?","Thank you so much adventurer.";
		illusion_moonlight = 9;
		completequest 7788;
		getitem 25271,5;
		getexp 500000,500000;
		end;
	}
	mes "[ Muyeon ]";
	mes "Good luck investigating the phenomenon with Chunghae!","Once the nightmares are gone, we won't need to perform the ritual anymore!";
	next;
	mes "[ Muyeon ]";
	mes "How can I be sure, you ask?","I'm not sure. Heh heh.","They might not go away completely.","Who knows?";
	close;
	
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 2";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 3";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 4";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 8";
end;	
}

payon_in03,30,96,5	script	Jagyeom#ill_moon_pin	4_M_HUOLDARMY,{
	if(illusion_moonlight < 2){
		mes "[ Jagyeom ]";
		mes "Please observe proper manners inside the palace.";
		close;
	}
	if(illusion_moonlight == 2){
		npctalk "Muyeon... If you can't do it, no one else can!","",bc_self;
		end;
	}
	if(illusion_moonlight < 5){
		npctalk "Let's listen for now.","",bc_self;
		end;
	}
	if(illusion_moonlight == 5){
		mes "[ Jagyeom ]";
		mes "We should grasp the situation first.","It'll be great if you can help us, Adventurer.";
		close;
	}
	if(illusion_moonlight < 10){
		mes "[ Jagyeom ]";
		mes "Please observe proper manners inside the palace.";
		close;
	}
	mes "[ Jagyeom ]";
	mes "The Moonlight Flower are recreating the past in their nightmares.","In a way, they're also victims.";
	next;
	mes "[ Jagyeom ]";
	mes "I'll make sure no villagers gets close to the collapsed walls of reality and dreams.";
	close;
}

payon_in03,33,93,1	script	Young Scholar#ill_moon_pin	4_F_03,{
	if(illusion_moonlight < 2){
		mes "[ Young Scholar ]";
		mes "Payon is home for sacred creatures since ancient times.","A town isolated from the world by the mountains, the people of Payon way of thinking is different from the outside.";
		close;
	}
	if(illusion_moonlight == 2){
		npctalk "Muyeon is really upset. We should ask her what happened.","",bc_self;
		end;
	}
	if(illusion_moonlight < 5){
		npctalk "We should ask Muyeon what happened.";
		end;
	}
	if(illusion_moonlight == 5){
		mes "[ Young Scholar ]";
		mes "This is terrible.","I can't belive Muyeon had to deal with it on her own.","Those foxes must be angrier than I thought.";
		next;
		mes "[ Young Scholar ]";
		mes "We need to look into this further. I'd better go to the ruined village.";
		close;
	}
	mes "[ Young Scholar ]";
	mes "I'm going to stay in the ruined village and investigate this phenomenon.","But I'll need some form of protection. I'm going to take Junghee with me.";
	next;
	mes "[ Young Scholar ]";
	mes "It'd be great if you join us again. See you at the ruined village.";
	close;
}

payon_in03,30,96,5	duplicate(dummynpc)	Nine Tail Spirit#ill_moon_0	1180
payon_in03,35,96,3	duplicate(dummynpc)	Nine Tail Spirit#ill_moon_1	1180
payon_in03,30,93,7	duplicate(dummynpc)	Nine Tail Spirit#ill_moon_2	1180
payon_in03,35,93,1	duplicate(dummynpc)	Nine Tail Spirit#ill_moon_3	1180

pay_dun03,140,46,0	script	Shimmering Portal#ill_moon_in	4_ENERGY_BLUE,{
	if(illusion_moonlight < 5){
		mes "- The air is brimming with strange energy. -";
		mes "It's giving me an anxiety feeling.";
		close;
	}
	if(illusion_moonlight == 5){
		mes "There's a shimmering portal in the air.";
		next;
		cloaknpc("Young Scholar#ill_moon_pdun",false,getcharid(0));
		cloaknpc("Junghee#ill_moon_pdun",false,getcharid(0));
		npctalk "*Panting* You're here.","Young Scholar#ill_moon_pdun",bc_self;
		mes "[ Young Scholar ]";
		mes "I was alarmed when you suddenly disappeared.","Do you think this is one of the nightmares that Muyeon...";
		next;
		select("I'll have to figure that out.");
		npctalk "Me? What if I don't want to?","Junghee#ill_moon_pdun",bc_self;
		mes "[ Young Scholar ]";
		mes "Then, do you mind if I tag along?","You don't have to worry about me. Junghee can keep me safe.";
		next;
		npctalk "D-Don't touch anything!","Junghee#ill_moon_pdun",bc_self;
		mes "[ Young Scholar ]";
		mes "Then... should I touch this?";
		illusion_moonlight = 6;
		completequest 7780;
		setquest 7781;
		close2;
		specialeffect EF_SPINMOVE,AREA,"Young Scholar#ill_moon_pdun";
		specialeffect EF_DQ9_CHARGE,AREA,"Young Scholar#ill_moon_pdun";
		sleep2 350;
		npctalk "Arghhhhh-!","",bc_self;
		cloaknpc("Young Scholar#ill_moon_pdun",true,getcharid(0));
		sleep2 500;
		npctalk "Chunghae!","Junghee#ill_moon_pdun",bc_self;
		sleep2 2000;
		npctalk "That careless klutz!","Junghee#dun_dummy",bc_self;
		sleep2 500;
		specialeffect EF_SPINMOVE,AREA,"Junghee#ill_moon_pdun";
		specialeffect EF_DQ9_CHARGE,AREA,"Junghee#ill_moon_pdun";
		sleep2 350;
		cloaknpc("Junghee#ill_moon_pdun",true,getcharid(0));
		end;
	}
	mes "There is something on the other side of the shimmering portal.","What should I do?";
	next;
	if(select("Enter the portal.:Quit.") == 2){
		mes "Quit investigating.";
		close;
	}
	warp "pay_d03_i",140,44;
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 5";
end;
}

pay_dun03,143,45,4	duplicate(dummynpc)	Junghee#ill_moon_pdun	4_M_PAY_SOLDIER
pay_dun03,138,43,7	duplicate(dummynpc)	Young Scholar#ill_moon_pdun	4_F_03

pay_d03_i,140,46,0	script	Shimmering Portal#ill_moon_out	4_ENERGY_BLUE,{
	mes "I can go back to the ruined village.","What should I do?";
	next;
	if(select("Exit.:Do not exit.") == 2){
		end;
	}
	warp "pay_dun03",140,44;
	end;
}

pay_d03_i,149,45,4	script	Scholar Chunghae#ill_moon_ind	4_F_03,{
	if(illusion_moonlight == 6){
		mes "[ Chunghae ]";
		mes "Look at this place!","It looks exactly like the ruined village we were in a moments ago, and yet... it's different!";
		next;
		mes "[ Chunghae ]";
		mes "Also, there's something off about people and foxes here, and I saw a strange-looking mage among them.","What if he's responsible for this incident.";
		next;
		mes "[ Chunghae ]";
		mes "These foxes, villagers, and angry spirits...","They reminded me of the time when the village was buried under landslide.";
		next;
		mes "[ Chunghae ]";
		mes "We need to look around for more clues.","You'll help, won't you?";
		next;
		mes "[ Chunghae ]";
		mes "Let me know when you're ready.";
		illusion_moonlight = 7;
		completequest 7781;
		end;
	}
	if(checkweight(25271,1) == 0 || (MaxWeight - Weight) < 1000){
		mes "- You're carrying too many items to proceed with this quest. -";
		close;
	}
	switch(checkquest(7783,PLAYTIME)){
		case -1:
			break;
			
		case 0:
		case 1:
			mes "[ Chunghae ]";
			mes "Now I know this is not the ruined village.","Are we really inside a Moonlight Flower's nightmare?";
			next;
			mes "[ Chunghae ]";
			mes "That's what Muyeon said.","Their nightmares are coming true.";
			next;
			mes "[ Chunghae ]";
			mes "This place is a worth of a serious study.";
			end;
			
		case 2:
			mes "[ Chunghae ]";
			mes "Let's begin our investigation for the day, shall we?";
			mes "Maybe it's because this is a dream, but nothing about it has changed.";
			erasequest 7783;
			next;
			mes "[ Chunghae ]";
			mes "Let me know when you're ready.";
			close;	;			
	}
	switch(checkquest(7782,HUNTING)){
		case -1:
			mes "[ Chunghae ]";
			mes "I've talked to the villagers,","and many of them told me about some strange mage.";
			next;
			mes "[ Chunghae ]";
			mes "They said he casts powerful spells wherever he goes, and it was one of his spells that shook the ground and caused the fatal landslide. As a result, a lot of the villagers and foxes died.";
			next;
			mes "[ Chunghae ]";
			mes "I'm convinced that the mage is responsible for these rampant nightmares.","Maybe the nightmares would stop materializing if we get rid of their cause.";
			next;
			mes "[ Chunghae ]";
			mes "Of course, I could be wrong.","He could just be another character in the nightmares.";
			next;
			mes "[ Chunghae ]";
			mes "I want to know more than anything what tore the walls between reality and dreams.","Maybe this is even happening in other places too?";
			next;
			mes "[ Chunghae ]";
			mes "Anyway, please take care of the ^0000FFWizard of the Truth^000000 in this place.","It's time we deal with this quasi-reality.";
			next;
			mes "[ Chunghae ]";
			mes "He is pretty formidable. I wouldn't recommend ^0000FFfight him alone.^000000";
			next;
			if(select("Will do.:No, thanks.") == 2){
				mes "[ Chunghae ]";
				mes "Err, then I'll have to investigate something else.","But I won't resent you for this. I promise.";
				end;
			}
			mes "[ Chunghae ]";
			mes "Good luck.","That wizard looks pretty strong.","Please be careful.";
			setquest 7782;
			end;
			
		case 0:
		case 1:
			mes "[ Chunghae ]";
			mes "That ^0000CDenlightened mage^000000 looks dangerous.","Please stop him.";
			end;

		case 2:
			mes "[ Chunghae ]";
			mes "You're as experienced as I've heard.","Now, let's see how this affects the situation.";
			next;
			if(illusion_moonlight == 7){
				mes "[ Chunghae ]";
				mes "Remember what Muyeon said?","About the foxes' nightmares coming true, I mean.";
				next;
				mes "[ Chunghae ]";
				mes "I was thinking while looking around.","I think it's possible we're inside a Moonlight Flower's dream.";
				next;
				mes "[ Chunghae ]";
				mes "I don't know how it has been connected to reality,","but I'm certain of one thing:";
				next;
				mes "[ Chunghae ]";
				mes "The spirits of the Moonlight Flowers are still living in the past.","Back when their village was buried..";
				next;
				mes "[ Chunghae ]";
				mes "They died such a horrible death that they're unable to move on to the Netherworld.","And something has ignited their pent-up anger.";
				next;
				mes "[ Chunghae ]";
				mes "Here, there are truths that we cannot find anywhere else.","I guess I'll be staying here until I find them all.";
				next;
				mes "[ Chunghae ]";
				mes "Please deliver the news to Muyeon in the Detached Payon Palace.","Junghee and I will explore this place further.";
				illusion_moonlight = 8;
				setquest 7788;
				next;
			}
			mes "[ Chunghae ]";
			mes "I hope we can find an answer to this phenomenon.";
			erasequest 7782;
			setquest 7783;
			getitem 25271,1;
			getexp 300000,300000;
			end;
	}
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 6";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 7 && checkquest(7782,HUNTING) == -1";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"illusion_moonlight == 7 && checkquest(7782,HUNTING) == 2";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"iillusion_moonlight > 7 && checkquest(7783,PLAYTIME) == 2";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"iillusion_moonlight > 7 && checkquest(7782,HUNTING) == 2";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"iillusion_moonlight > 7 && checkquest(7783,PLAYTIME) == -1 && checkquest(7782,HUNTING) == -1";
end;
}

pay_d03_i,152,45,4	script	Soldier Junghee#ill_moon_ind	4_M_PAY_SOLDIER,{
	if(illusion_moonlight == 6){
		mes "[ Junghee ]";
		mes "I knew coming in that I'd better stay close to Chunghae.","I was right.";
		next;
		mes "[ Junghee ]";
		mes "I'm sensing really bad vibes from these foxes and ghosts.","This is not good.";
		close;
	}
	if(checkweight(25271,1) == 0 || (MaxWeight - Weight) < 1000){
		mes "- You're carrying too many items to proceed with this quest. -";
		close;
	}
	if(checkquest(7784,HUNTING) == 2){
		mes "[ Junghee ]";
		mes "It doesn't matter if they're real or not. They're just as threatening.","Good Job.";
		next;
		mes "[ Junghee ]";
		mes "Chunghae's almost done investigating this place. I'd better get ready to leave.";
		erasequest 7784;
		setquest 7785;
		getitem 25271,1;
		questinfo_refresh();
		end;
	}
	if(checkquest(7786,HUNTING)  == 2){
		mes "[ Junghee ]";
		mes "It doesn't matter if they're real or not.","I can symphatize with the soldier.";
		next;
		mes "[ Junghee ]";
		mes "All he wanted to do was protect others, and he died without fulfilling that wish.","Thank you for helping them rest.";
		erasequest 7786;
		setquest 7787;
		getitem 25271,1;
		questinfo_refresh();
		end;
	}
	mes "[ Junghee ]";
	mes "There's another portal that looks just like the one we came through.","I touched it, and it sent me back to the original ruined village.";
	next;
	if(select("About the angry Nine Tails.:About the angry Soldiers.") == 1){
			switch(checkquest(7785,PLAYTIME)){
				case -1:
					break;
				case 0:
				case 1:
					mes "[ Junghee ]";
					mes "Chunghae said we're inside a Moonlight Flower's nightmare.","They may not be real, but if they pose any threat to the living, then they must be taken care of.";
					next;
					mes "[ Junghee ]";
					mes "And that has nothing to do with the symphathy I feel for them.","Now if you'll excuse me, Chunghae and I'll go investigate other places.";
					end;
				case 2:
					erasequest 7785;
					mes "Did you get some rest?";
					mes "Everything's just the same as when you left it, but I want to clear this place,";
					next;
					break;
			}
			switch(checkquest(7784,HUNTING)){
				case -1:
					mes "[ Junghee ]";
					mes "Chunghae is having a problem investigating this place because of the angry foxes.","I'll appreciate if you can take care of them.";
					next;
					if(select("Accept:Decline") == 2){
						mes "[ Junghee ]";
						mes "Then Chunghae won't be able to fully investigate this place.";
						end;
					}
					mes "[ Junghee ]";
					mes "Thank you.","I understand why those ^0000FFfoxes are angry^000000, but this has to be done.";
					setquest 7784;
					end;
					
				case 0:
				case 1:
					mes "[ Junghee ]";
					mes "Please hunt the ^0000FFAngry Nine Tails^000000 around this place.","That'll ensure Chunghae's safety during his investigation.";
					close;
			}
	} else {
			switch(checkquest(7787,PLAYTIME)){
				case -1:
					break;
				case 0:
				case 1:
					mes "[ Junghee ]";
					mes "If we're really inside Moonlight Flower's nightmare, like Chunghae thinks,","then the angry soldier over there must have been the guard of this village.";
					next;
					mes "[ Junghee ]";
					mes "It doesn't matter if this is real or not. Watching my ancestors suffer is difficult.","I may end up wasting our time, but I want to try to help them rest.";
					close;
				case 2:
					erasequest 7787;
					mes "[ Junghee ]";
					mes "What can we do to get rid of these nightmares?";
					mes "I told you it's difficult for me to look at those soldiers without feeling pain.";
					next;
					break;
			}
			switch(checkquest(7786,HUNTING)){
				case -1:
					mes "[ Junghee ]";
					mes "These soldiers tried to protect their villagers until the last moment,","and got buried with them. No wonder they're so angry.";
					next;
					mes "[ Junghee ]";
					mes "Would you be so kind as to put them to rest for me?";
					next;
					if(select("Accept.:Decline.") == 2){
						mes "[ Junghee ]";
						mes "I really don't want to deal with them myself,","but I guess I'll have to.";
						end;
					}
					mes "[ Junghee ]";
					mes "Thank you.","I'll leave the ^0000FFAngry Soldiers^000000 to you.","Please send them to heaven.";
					setquest 7786;
					end;
					
				case 0:
				case 1:
					mes "[ Junghee ]";
					mes "Please take care of the ^0000FFAngry Soldiers^000000 in this place.","I mean... send them to Heaven.";
					close;
			}
	}
	end;
	
OnInit:
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"illusion_moonlight > 6 && checkquest(7785,PLAYTIME) == -1 && checkquest(7784,HUNTING) == -1";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"illusion_moonlight > 6 && checkquest(7787,PLAYTIME) == -1 && checkquest(7786,HUNTING) == -1";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"illusion_moonlight > 6 && checkquest(7785,PLAYTIME) == 2";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"illusion_moonlight > 6 && checkquest(7787,PLAYTIME) == 2";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"illusion_moonlight > 6 && checkquest(7784,HUNTING) == 2";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"illusion_moonlight > 6 && checkquest(7786,HUNTING) == 2";
end;
}

pay_d03_i,160,45,4	script	Gemcutter#ill_moon_merchant	4_TOWER_17,{
	mes "[ Gemcutter ]";
	mes "Do you have business with me?";
	next;
	switch(select("What are you doing here?:Upgrade Weapon.:Upgrade Armor.")){
		case 1:
			mes "[ Gemcutter ]";
			mes "I came to the ruined village,","looking for some materials. Touched some strange light, and now I'm here.";
			next;
			mes "[ Gemcutter ]";
			mes "I've decided to stick around for a little while. Figured I'd be safe so long as I stay close to this soldier.","I have a proposition for you. I want some materials that can only be found in this place.";
			next;
			mes "[ Gemcutter ]";
			mes "Get them for me, and I'll improve your equipment in exchange. Just so you know, I can only improve certain types.";
			next;
			mes "[ Gemcutter ]";
			mes "If you're interested, we can discuss the details of our bargain.";
			close;
			
		case 2:
			disable_items;
			if(checkweight(25271,1) == 0 || (MaxWeight - Weight) < 1000){
				mes "- You're carrying too many items to proceed. -";
				close;
			}
			mes "[ Gemcutter ]";
			mes "The following is the list of equipment I can handle.";
			for(.@i = 0; .@i < getarraysize(.weapons$); .@i++){
				explode(.@T$,.weapons$[.@i],"|");
				.@item_id = atoi(.@T$[0]);
				mes "<ITEM>"+getitemname(.@item_id)+"<INFO>"+.@item_id+"</INFO></ITEM>";
			}
			next;
			mes "[ Gemcutter ]";
			mes "Make sure ^0000FFyour equipment is refined to at least +7^000000 before bringing it to me.","That's the minimum requirement for my upgrade service to have any visible effects on your equipment.";
			next;
			mes "[ Gemcutter ]";
			mes "Make sure you're ^0000FFequipped with the item that you want to improve.^000000","Otherwise, I can't evaluate its condition.";
			next;
			mes "[ Gemcutter ]";
			mes "As you may have guessed, your equipment will transform into something new after this.","In other words, ^0000FFIt'll lose its current refining levels, cards and enchantments.^000000";
			next;
			mes "[ Gemcutter ]";
			mes "And I need ^0000FFIllusion Stones and some other materials^000000 to upgrade your equipment.","Pick an item you want and I'll tell you what I need.";
			next;
			for(.@i = 0; .@i < getarraysize(.weapons$); .@i++){
				explode(.@T$,.weapons$[.@i],"|");
				.@item_id = atoi(.@T$[0]);
				.@menu$ += getitemname(.@item_id) +":";
			}
			.@s = select(.@menu$) - 1;
			explode(.@T$,.weapons$[.@s],"|");
			explode(.@TT$,.@T$[2],",");
			mes "[ Gemcutter ]";
			mes "For that equipment, I need the following materials.";
			mes "^0000FF+7 " + getitemname(atoi(.@T$[1])) + "^000000";
			for(.@i = 0; .@i < getarraysize(.@TT$); .@i++){
				explode(.@data$,.@TT$[.@i],":");
				.@item_id[.@i] = atoi(.@data$[0]);
				.@amount[.@i] = atoi(.@data$[1]);
				mes "^0000FF" + .@amount[.@i] +" "+ getitemname(.@item_id[.@i]) + "^000000";
			}
			mes "Do you want to continue?";
			next;
			if(select("Continue.:I'll bring those materials") == 2){
				mes "[ Gemcutter ]";
				mes "Comeback when you're ready.";
				close;
			}
			if(getequipid(EQI_HAND_R) != atoi(.@T$[1])){
				mes "[ Gemcutter ]";
				mes "You must equip the " + getitemname(atoi(.@T$[1])) + " before proceeding.";
				close;
			}
			for(.@i = 0; .@i < getarraysize(.@item_id); .@i++){
				if(countitem(.@item_id[.@i]) < .@amount[.@i])
					.@miss++;
			}
			if(getequiprefinerycnt(EQI_HAND_R) < 7 || .@miss > 0){
				mes "[ Gemcutter ]";
				mes "You don't have all the materials";
				end;
			}
			mes "[Illusion Researcher]";
			mes "I upgraded your item... This was a good research for me.";
			delequip(EQI_HAND_R);
			for(.@i = 0; .@i < getarraysize(.@item_id); .@i++)
				delitem .@item_id[.@i],.@amount[.@i];
			getitem atoi(.@T$[0]),1;			
			break;
			
			
		case 3:
			disable_items;
			if(checkweight(25271,1) == 0 || (MaxWeight - Weight) < 1000){
				mes "- You're carrying too many items to proceed. -";
				close;
			}
			mes "[ Gemcutter ]";
			mes "The following is the list of equipment I can handle.";
			for(.@i = 0; .@i < getarraysize(.armors$); .@i++){
				explode(.@T$,.armors$[.@i],"|");
				.@item_id = atoi(.@T$[0]);
				mes "<ITEM>"+getitemname(.@item_id)+"<INFO>"+.@item_id+"</INFO></ITEM>";
			}
			next;
			mes "[ Gemcutter ]";
			mes "Make sure ^0000FFyour equipment is refined to at least +7^000000 before bringing it to me.","That's the minimum requirement for my upgrade service to have any visible effects on your equipment.";
			next;
			mes "[ Gemcutter ]";
			mes "Make sure you're ^0000FFequipped with the item that you want to improve.^000000","Otherwise, I can't evaluate its condition.";
			next;
			mes "[ Gemcutter ]";
			mes "As you may have guessed, your equipment will transform into something new after this.","In other words, ^0000FFIt'll lose its current refining levels, cards and enchantments.^000000";
			next;
			mes "[ Gemcutter ]";
			mes "And I need ^0000FFIllusion Stones and some other materials^000000 to upgrade your equipment.","Pick an item you want and I'll tell you what I need.";
			next;
			for(.@i = 0; .@i < getarraysize(.armors$); .@i++){
				explode(.@T$,.armors$[.@i],"|");
				.@item_id = atoi(.@T$[0]);
				.@menu$ += getitemname(.@item_id) +":";
			}
			.@s = select(.@menu$) - 1;
			explode(.@T$,.armors$[.@s],"|");
			explode(.@TT$,.@T$[2],",");
			.@slot = atoi(.@T$[3]);
			mes "[ Gemcutter ]";
			mes "For that equipment, I need the following materials.";
			mes "^0000FF+7 " + getitemname(atoi(.@T$[1])) + "^000000";
			for(.@i = 0; .@i < getarraysize(.@TT$); .@i++){
				explode(.@data$,.@TT$[.@i],":");
				.@item_id[.@i] = atoi(.@data$[0]);
				.@amount[.@i] = atoi(.@data$[1]);
				mes "^0000FF" + .@amount[.@i] +" "+ getitemname(.@item_id[.@i]) + "^000000";
			}
			mes "Do you want to continue?";
			next;
			if(select("Continue.:I'll bring those materials") == 2){
				mes "[ Gemcutter ]";
				mes "Comeback when you're ready.";
				close;
			}
			if(getequipid(.@slot) != atoi(.@T$[1])){
				mes "[ Gemcutter ]";
				mes "You must equip the " + getitemname(atoi(.@T$[1])) + " before proceeding.";
				close;
			}
			for(.@i = 0; .@i < getarraysize(.@item_id); .@i++){
				if(countitem(.@item_id[.@i]) < .@amount[.@i])
					.@miss += 1;
			}
			if(getequiprefinerycnt(.@slot) < 7 || .@miss > 0){
				mes "[ Gemcutter ]";
				mes "You don't have all the materials";
				end;
			}
			mes "[ Gemcutter ]";
			mes "I upgraded your item... This was a good research for me.";
			delequip(.@slot);
			for(.@i = 0; .@i < getarraysize(.@item_id); .@i++)
				delitem .@item_id[.@i],.@amount[.@i];
			getitem atoi(.@T$[0]),1;			
			break;			
	}
	next;
	mes "[ Gemcutter ]";
	mes "Here is your upgraded equipment.";
	end;
	
OnInit:
	setarray .weapons$,
		"26109|1648|25271:30,25256:100",
		"28725|1234|25271:30,25256:100",
		"16063|1525|25271:10,25256:20",
		"26007|1477|25271:10,25256:100";
	setarray .armors$,
		"19209|2277|25271:10,25257:100|6",
		"19210|2285|25271:10,25258:100|6",
		"15195|15012|25271:10,25256:100|7",
		"20838|2504|25271:10,23228:100|3",
		"22133|2404|25271:10,23228:100|2";
end;
}


//= Non-moving monster
pay_d03_i	monster	Blue Plant	1079,1,5000,0
pay_d03_i	monster	Green Plant	1080,1,5000,0
pay_d03_i	monster	Yellow Plant	1081,1,5000,0
pay_d03_i	monster	White Plant	1082,5,5000,0
pay_d03_i	monster	Whisper	1185,1,5000,0
pay_d03_i,154,112	monster	Whisper	1185,1,5000,0
pay_d03_i,161,117	monster	Whisper	1185,1,5000,0
pay_d03_i,84,63	monster	Whisper	1185,1,5000,0
pay_d03_i,81,61	monster	Whisper	1185,1,5000,0


//= Illusion Moonlight Spawn
pay_d03_i,43,150,5	script	Villager#ill_moon_0	1_F_ORIENT_01,{
	mes "[ Villager ]";
	mes "Adventurer?";
	mes "Are you with the subjugation party?";
	mes "Why can't you just leave us alone?";
	next;
	mes "[ Villager ]";
	mes "We don't worship monsters.";
	mes "We're not enthralled by monsters!";
	mes "[ Villager ]";
	mes "Ah...";
	mes "The light... The magic... Please stop that magic...";
	close2;
	initnpctimer;
	disablenpc strnpcinfo(0);
	specialeffect EF_QUAKEBODY2;
	npctalk "Ah... Ah... Aaahhh...";
	areamonster "pay_d03_i",42,149,44,151,"Resentful Sohee",3762,3;
	end;
	
OnTimer60000:
	stopnpctimer;
	enablenpc strnpcinfo(0);
end;
}

pay_d03_i,82,237,3	script	Villager#ill_moon_1	1_F_ORIENT_01,6,6,{
	end;
	
OnTouch:
	specialeffect EF_QUAKEBODY2;
	npctalk "Ahhh... Ahhhhh!!";
	initnpctimer;
	disablenpc strnpcinfo(0);
	areamonster "pay_d03_i",81,236,83,238,"Resentful Sohee",3762,3;
end;
	
OnTimer60000:
	stopnpctimer;
	enablenpc strnpcinfo(0);
end;
}

pay_d03_i,254,206,3	script	Villager#ill_moon_2	4_F_01,6,6,{
	end;
	
OnTouch:
	specialeffect EF_QUAKEBODY2;
	npctalk "Something is not right!";
	sleep2 2000;
	npctalk "Stop it... It's coming, agh!!";
	areamonster "pay_d03_i",252,204,255,208,"Resentful Munak",3760,3;
	hideonnpc strnpcinfo(0);
	disablenpc strnpcinfo(0);
end;
	
OnTimer60000:
	stopnpctimer;
	enablenpc strnpcinfo(0);
end;
}

pay_d03_i,81,136,3	script	Villager#ill_moon_3	1_M_ORIENT01,{
	mes "[ Villager ]";
	mes "Are you here to subjugate us?!";
	mes "We've done nothing wrong!";
	mes "Can't you tell from the sacred creatures!";
	next;
	mes "[ Villager ]";
	mes "Ah... The fox lady...";
	close2;
	initnpctimer;
	hideonnpc strnpcinfo(0);
	disablenpc strnpcinfo(0);
	npctalk "H-help!! I don't want to die!";
	areamonster "pay_d03_i",79,136,81,138,"Resentful Bongun",3761,3;
	end;
	
OnTimer60000:
	stopnpctimer;
	enablenpc strnpcinfo(0);
end;
}

pay_d03_i,160,260,3	script	Villager#ill_moon_4	1_M_ORIENT01,{
	mes "[ Villager ]";
	mes "You...";
	mes "Who's that strange mage?";
	mes "Why do you...?";
	next;
	mes "[ Villager ]";
	mes "You! You're no better than them!";
	mes "What have we done to you?";
	close2;
	initnpctimer;
	hideonnpc strnpcinfo(0);
	disablenpc strnpcinfo(0);
	npctalk "Arrgghh-!";
	areamonster "pay_d03_i",158,258,162,262,"Resentful Bongun",3761,3;
	end;
	
OnTimer60000:
	stopnpctimer;
	enablenpc strnpcinfo(0);
end;
}

-	script	illusion_mob#moonlight	-1,{
	end;

OnKill:
	if(!.mvp_spawn)
		end;
	.kill_count += 1;
	if(.kill_count < .trigger){
		if(rand(1,100) <= 10)
			donpcevent strnpcinfo(0)+"::OnBossSpawn";
	}
end;

OnBossSpawn:
	.mvp_spawn = 0;
	.kill_count = 0;
	monster "pay_d03_i",0,0,"Angry Moonlight Flower",3758,1;
	mapannounce "pay_d03_i","Angry Moonlight Flower : Who dares bully us again? They're in a lot of trouble.",bc_map;
end;

OnBossKill:
	.mvp_spawn = 1;
	.kill_count = 0;
end;
	
OnInit:
	.mvp_spawn = 1;
	.kill_count = 0;
	.trigger = 1000;
end;
}

pay_d03_i	monster	Resentful Munak	3760,20,5000,0
pay_d03_i	monster	Resentful Bongun	3761,20,5000,0
pay_d03_i	monster	Resentful Sohee	3762,20,5000,0
pay_d03_i	monster	Resentful Soldier	3763,10,5000,0
pay_d03_i	monster	Deranged Adventurer	3765,5,15000,0
pay_d03_i,55,75	monster	Wizard of the Truth	3764,1,30000,0
pay_d03_i	monster	Angry Nine Tail	3759,15,5000,0,"illusion_mob#moonlight::OnKill"