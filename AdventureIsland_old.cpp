/* Group 3: Tylor Cooks
            Kevin Nower
            Tim Diliberto
            Nathan Garza
*/

#include <iostream>
#include <string> 
#include <iomanip>

using namespace std;

/* 
   declaring all of the rooms as enumerated data types
   original order: Shore, Banana Tree, Gangplank, Main Deck, Wheel, 
                   Capn Qtr, Lower Deck, Galley, Cargo, Brig, End
*/
enum Rooms {SHORE, BANANA_TREE, GANGPLANK, TOP_DECK, CROWS_NEST, WHEEL,
            BOW, CAP_QTR, LVNG_QTR, BOTTOM_DECK, GALLEY, CAMP, INFIRMARY,
            CARGO, ARMORY, BRIG, PATHWAY, END};

void introduction();
void instructions();

// initialization for objects and features of each room
struct Location {
    bool bottle;
    bool bananas;
    bool pouch;
    bool knife;
    bool flint;
    bool gunpowder;
    bool map;
    bool cloth;
    bool treasure;
    bool keys;
    bool bomb;
    bool gorilla;
    bool natives;
    bool anchor;
    bool prisoner;
    bool gamePlay;
    bool firstTime;
    string name;
    string longDescription;
    string shortDescription;
    string wrongDirections;
    Rooms north;
    Rooms south;
    Rooms east;
    Rooms west;    
    Rooms up;
    Rooms down;
};
    
// initializing various aspects of the Hero
struct Hero {
    bool win;
    bool gamePlay;
    bool bottle;
    bool bananas;
    bool pouch;
    bool knife;
    bool map;
    bool treasure;
    bool keys;
    bool flint;
    bool gunpowder;
    bool bomb;
    bool cloth;
        
    string name;
    string userInput;
    Rooms curLoc;    
};

void intro();    
Hero initializeHero();
void roomCreate(Location[]);
void roomsInfo(Location[]);
void description(Hero &, Location[]);

void read(Hero &);
void execute(Hero &, Location[]);
void actionPath(Hero &, Location[]);

void natives(Hero &, Location[]);
void gorilla(Hero &, Location[]);

void cut(Hero &, Location [], string);
void drop(Hero &, Location[], string);
void eat(Hero &, string);
void give(Hero &, Location [], string);
void destroy(Hero &, string);
void sail(Hero &, Location []);
void search(Hero &, Location[]);
void take(Hero &, Location[], string);
void unlock(Hero &, Location [], string);
void use(Hero &, Location[], string);
void playerRead(Hero &, Location[], string);
void pigLatin(Hero &, Location []);

void help();
void map();

/* 
   our main function creates the Hero and the map. It then calls the 
   introduction which leads into actionPath, setting the rest of the game
   in motion. will remain true so long as player.gamePlay = true.
*/
int main() {
    Hero player;
    player = initializeHero();
    Location roomList[END];
    roomCreate(roomList);
    
    intro();

    do {
        actionPath(player, roomList);
    }
    
    while (player.gamePlay);
    
    return 0;    
}

/* 
   the visual introduction into the game, giving a short premise and 
   allowing the user to input commands
*/
void intro() {
    cout << "\nWelcome to ADVENTURE ISLAND!\n";
    cout << "\nYou have just awakened on the shore of a strange island" 
         << "with a\n";
    cout << "terrible headache. You can't remember anything about"
         << "yourself, where\n";
    cout << "you are, or where you came from.\n"; 
    cout << "\nPlease press ENTER to play!\n";
    
    // NEED TO FIX --- Either fail-proof ENTER or start the game
    // immediately or no matter what the user presses
    // ^ Might be old note
    
    cin.get();
    
    cout << setfill('-') << setw(80)<< "-" << endl;
    cout << endl;
}

/*
    This function initializes the hero by setting the start location to 
    the SHORE and starting equiptment to nothing
*/
Hero initializeHero() {
    
    Hero tempPlayer;
    
    tempPlayer.win = false;
    tempPlayer.gamePlay = true;
    tempPlayer.bottle = false;
    tempPlayer.bananas = false;
    tempPlayer.pouch = false;
    tempPlayer.cloth = false;
    tempPlayer.knife = false;
    tempPlayer.flint = false;
    tempPlayer.gunpowder = false;
    tempPlayer.bomb = false;
    tempPlayer.map = false;
    tempPlayer.treasure = false;
    tempPlayer.keys = false;
    
    tempPlayer.curLoc = SHORE;
    
    return tempPlayer;    
}

/*
    this function starts by creating each of the rooms in a general sense,
    meaning each room does not have any value or items. after the roomsInfo
    (rooms) is called, it creates each individual and unique room by 
    setting directions and objects to be true in their respective rooms
*/
void roomCreate(Location room[]) { 
    for (int i = 0; i < END; i++) {
        room[i].north = END;
        room[i].west = END;
        room[i].south = END;
        room[i].east = END;
        room[i].up = END;
        room[i].down = END;  
        room[i].bottle = false;
        room[i].bananas = false;
        room[i].pouch = false;
        room[i].knife = false;
        room[i].map = false;
        room[i].treasure = false;
        room[i].keys = false;
        room[i].anchor = false;
        room[i].gorilla = false;
        room[i].natives = false;
        room[i].flint = false;
        room[i].gunpowder = false;
        room[i].bomb = false;
        room[i].firstTime = true;
    }

//Items in rooms initial start    
    room[SHORE].bottle = true;
    room[BANANA_TREE].bananas = true;
    room[CAMP].knife = true;
    room[GANGPLANK].natives = true;
    room[CROWS_NEST].pouch = true;
    room[WHEEL].gorilla = true;
    room[CAP_QTR].knife = true;    
    room[CAP_QTR].map = true;
    room[CARGO].treasure = true;
    room[ARMORY].gunpowder = true;
    room[INFIRMARY].flint = true;
    room[LVNG_QTR].cloth = true;
    room[BOW].anchor = true;
    
//Rooms orientation    
    room[BANANA_TREE].east = SHORE;
    room[SHORE].west = BANANA_TREE;
    room[SHORE].east = GANGPLANK;
    room[GANGPLANK].east = TOP_DECK;
    room[GANGPLANK].west = SHORE;
    room[TOP_DECK].north = BOW;
    room[TOP_DECK].south = PATHWAY;
    room[TOP_DECK].west = GANGPLANK;
    room[TOP_DECK].up = CROWS_NEST;
    room[TOP_DECK].down = BOTTOM_DECK;
    room[PATHWAY].north = TOP_DECK;
    room[PATHWAY].south = CAP_QTR;
    room[PATHWAY].up = WHEEL;    
    room[CROWS_NEST].down = TOP_DECK;
    room[BOW].south = TOP_DECK;
    room[WHEEL].north = TOP_DECK;
    room[WHEEL].down = TOP_DECK;
    room[CAP_QTR].north = TOP_DECK;
    room[BOTTOM_DECK].north = INFIRMARY;
    room[BOTTOM_DECK].south = LVNG_QTR; 
    room[BOTTOM_DECK].up = TOP_DECK;
    room[BOTTOM_DECK].down = CARGO;
    room[INFIRMARY].north = GALLEY;
    room[INFIRMARY].south = BOTTOM_DECK;
    room[GALLEY].south = INFIRMARY;
    room[LVNG_QTR].north = BOTTOM_DECK;
    room[CARGO].south = BRIG;
    room[CARGO].up = BOTTOM_DECK;
    room[CARGO].north = ARMORY;
    room[BRIG].north = CARGO; 
    room[ARMORY].south = CARGO;
    
    room[BANANA_TREE].west = CAMP;                
    room[CAMP].east = BANANA_TREE;
    
/*
    this function's main purpose is to set the visual name and description
    for each of the rooms. The name will be given each time the player
    enters the room, whereas the description will only be outputted the
    first time the room is entered or when prompted by the user
*/
    room[SHORE].name = "SHORE";
    room[BANANA_TREE].name = "BANANA TREE";
    room[GANGPLANK].name = "GANGPLANK";
    room[TOP_DECK].name = "TOP DECK";
    room[CROWS_NEST].name = "CROW'S NEST";
    room[BOW].name = "BOW";
    room[CAP_QTR].name = "CAPTIAN'S QUARTERS";
    room[LVNG_QTR].name = "LIVING QUARTERS";
    room[BOTTOM_DECK].name = "BOTTOM DECK";
    room[GALLEY].name = "GALLEY";
    room[INFIRMARY].name = "INFIRMARY";
    room[CARGO].name = "CARGO HOLD";
    room[BRIG].name = "BRIG";
    room[PATHWAY].name = "STAIRS";
    room[ARMORY].name = "ARMORY";
    room[CAMP].name = "NATIVES CAMP";
    room[WHEEL].name = "WHEEL";
                                    
    room[SHORE].longDescription = "The island is forested with banana"
       " trees.  Most of the bananas are green but one\n"
       "tree to your west might have ripe bananas in reach. There appears"
       " to be a bottle\n"
       "that has washed up on the shore. You hear ominous drums off in"
       "the distance.\n" 
       "There is a pirate ship to your east with a gangplank to board the"
       " ship.";
                                         
    room[BANANA_TREE].longDescription = "There is a large banana tree"
       " here. You can see one bunch of ripe bananas on the\n"
       "tree within reach and also a little monkey. Hope he doesn't take"
       "it before you.\n";
                                                
    room[GANGPLANK].longDescription = "You are on a gankplank which has"
       "access to the pirate ship to the east.";
    
    room[TOP_DECK].longDescription =  "The main deck has access to most"
       "of the ship. To the north, there is the bow of\n"
       "the ship. To the south, there are stairs to the wheel and a door"
       "to captain's\n"
       "quarters. At the wheel, there appears to be a giant gorilla."
       "Above you, you\n"
       "can make out a crow's nest, and down below, you see a hatch to"
       "the lower deck.\n"
       "There are some barrels at the base of the crow's nest.";

    room[CROWS_NEST].longDescription = "Although you can see far in every"
       "direction, you cannot make out too much with\n"
       "your naked eye. However you see a light coming from west of the"
       "banana tree\n"
       "near the shore. There also appears to be a small pouch next to"
       "you.";
    
    room[WHEEL].longDescription = "You see the wheel that steers the"
        "ship. That blow to the head made you forget\n"
        "almost everything about sailing. You will not be able to set"
        "sail alone.";
        
    room[BOW].longDescription = "There are old cannons as well as grungy"
        "supplies that cannot be used.\n"
        "There is a singular barrel at the very front of the ship as well"
        "as a\n"
        "chain attached to the upper frame. The chain appears to be"
        "connected \n"
        "to the anchor which is cemented in the sand down below. That"
        "chain\n"
        "is preventing the ship from moving...";
    
    room[CAP_QTR].longDescription = "There is a bed with a nightstand" 
        "here. In the middle of the room, there is a\n"
        "table with maps and papers on it. In the nightstand, there might"
        "be a knife.\n";
    
    room[LVNG_QTR].longDescription = "You are in the main wing of the"
        "living quarters. There are two beds in this\n"
        "wing, each with a trunk and a nightstand. The room seems to be"
        "fairly intact,\n"
        "beds untouched for the most part. The only door is to your"
        "north.\n";
                                       
    room[BOTTOM_DECK].longDescription = "The deck below is dimly lit, and"
        "smells musty. Just north of you is the\n"
        "infirmary. To the south are the living quarters and below you"
        "there is a hatch\n"
        "that should lead to the cargo hold.";
    
    room[GALLEY].longDescription = "It is mostly empty, but in a shadowy"
        "corner you see a parrot sitting on a perch.";
    
    room[INFIRMARY].longDescription = "This is where any sick pirate"
        "would go to seek aide. It has only few supplies\n"
        "left, and most may be too worn-down to be useful.\n"
        "To the north you see a door to the galley, and to the south is"
        "the lower\n"
        "deck.";
    
    room[CARGO].longDescription = "There are barrels, a pile of tools,"
        "and a trunk. There are doors to your north\n"
        "and south.";
            
    room[BRIG].longDescription = "In the very bowels of the ship, you"
        "stumble upon the brig. There is very little\n"
        "here besides the cells and a prisoner occupying one of them.\n\n"
        "It seems as though the prisoner seems eager to talk to you...";
        "You approach the prisoner. He says,\n"  
        "'I'm so glad found me! The cap'n locked me up fer'\n" 
        "'cheatin' at cards. That be the reason the natives didn't get'\n"
        "'me. They either killed the rest or took 'em to their camp.'\n" 
        "'Find the keys to this cell, and we can sail out of here!'\n" 
        "'Come back if you need any help, but beware! That bird is a'\n"
        "'tricky one!'\n";
        
    room[PATHWAY].longDescription = "You stop at some stairs. You can"
        "either go up to the wheel, south\n"
        "to the Captain's Quarters, or back the top deck.";
                                        
    room[ARMORY].longDescription = "The room has been pretty scavenged,"
        "however it's impossible they took\n"
        "everything.\n";
                                        
    room[CAMP].longDescription = "There isn't anyone here however the" 
        "fires seem to have been recently\n"
        "extinguished. It looks like this camp belongs to the natives due"
        "to \n"
        "all the unusual items lying around. You notice something of a" 
        "knife\n"
        "next to one of the fire pits.";
}                                        
    
/*
    the counterpart to the prior, this function calls each room's name and
    description depending on its status as having been visited or not
*/
void description(Hero &heroStatus, Location room[]) {  
    if (room[heroStatus.curLoc].firstTime) {
        cout << "You are currently at the " << room[heroStatus.curLoc].name
             << "." << endl;
        cout << endl;
        cout << room[heroStatus.curLoc].longDescription << endl;
        room[heroStatus.curLoc].firstTime = false;
    }
    
    else {
        cout << "You are currently at the " << room[heroStatus.curLoc].name
        << "." << endl;
    }
}
 
/*
    the primary function that reads user input and sends it on to each
    appropriate function
*/
void read(Hero &input) {
    
    cout << endl;
    cout << ">>";
    getline(cin, input.userInput);
    cout << endl;
    cout << setfill('-') << setw(80)<< "-" << endl;
}
    
/*
    this function takes the user input from read and determines whether
    the input is a verb, a noun, or neither. it will then read the
    specific string and send it to its respective function. for verbs
    and/or nouns with a simpler purpose in the game, such as inventory,
    they are called and completed within the execute function
*/
void execute(Hero &player, Location room[]) {
    
    string verb, noun;
    char response;
        
    verb.assign(player.userInput,0,player.userInput.find(' '));

    noun = player.userInput.erase(0, player.userInput.find(' ')+1);
    noun.assign(noun,0, noun.find(' '));
    
    for (int i=0; i < verb.length(); i++) {
        
        verb[i]=toupper(verb[i]);
    }
        
    for (int i=0; i < noun.length(); i++) {
            noun[i]=toupper(noun[i]);
    }        
            
    if ((verb == "GO" or verb == "MOVE") and noun != verb) {
        player.userInput = noun;
    } else if (verb == "NORTH") {
        player.userInput = verb;
    } else if (verb == "EAST") {
        player.userInput = verb;
    } else if (verb == "SOUTH") {
        player.userInput = verb;
    } else if (verb == "WEST") {
        player.userInput = verb;
    } else if (verb == "UP") {
        player.userInput = verb;
    } else if (verb == "DOWN") {
        player.userInput = verb;
    } else if (verb == "N") {
        player.userInput = "NORTH";
    } else if (verb == "S") {
        player.userInput = "SOUTH";
    } else if (verb == "E") {
        player.userInput = "EAST";
    } else if (verb == "W") {
        player.userInput = "WEST";
    } else if (verb == "U") {
        player.userInput = "UP";
    } else if (verb == "D") {
        player.userInput = "DOWN";
    } else if (verb == "LOOK" or verb == "OBSERVE") {
        room[player.curLoc].firstTime = true;
    } else if (verb == "EAT") {
        eat(player, noun);
    } else if (verb == "SEARCH" or verb == "EXPLORE") {
        search(player, room);
    } else if (verb == "BOARD") {
                
        if (player.curLoc == GANGPLANK) {
            player.userInput = "EAST";
        } else {
            cout << "There is nothing to board" << endl;
        }
    } else if (verb == "INVENTORY") {
        cout << "\nYou are carrying:" << endl;
                
        if (player.keys == true)
            cout << "A set of keys" << endl;
                    
        if (player.knife == true)
            cout << "A sturdy knife" << endl;
                    
        if (player.bananas == true)
            cout << "A bunch of bananas" << endl;
                    
        if (player.treasure == true)
            cout << "Valuable treasure" << endl;
            
        if (player.bottle == true)
            cout << "A message in a bottle" << endl;
        
        if (player.pouch == true)
            cout << "A pouch" << endl;
        
        if (player.map == true)
            cout<<"A map of the ship"<<endl;
        
        if (player.flint == true)
            cout<<"A piece of flint"<<endl;
        
        if (player.gunpowder == true)
            cout<<"A pouch of gun powder"<<endl;
            // else cout<<"Noting"<<endl;
        } else if (verb == "TALK") {
                
        if (player.curLoc == GALLEY)
            pigLatin(player, room);
        else {
            cout << "\nThere is no one to talk to except for yourself." 
                 << endl;
        }
    } else if (verb == "TAKE" or verb == "GRAB" or verb == "GET") {
        take(player, room, noun);
    } else if (verb == "GIVE") {
        give(player, room, noun)else if (verb == "DESTROY" or verb == "DISCARD") {
        destroy(player, noun);
    }
                                
    else if (verb == "DROP") {
        drop(player, room, noun);
    }
    
    else if (verb == "IGNITE" or verb == "LIGHT") {
        if(player.bomb == true & player.knife == true 
             & player.flint == true) {
            if (player.curLoc == BOW) { 
                cout << "Using your flint and knife you prime the bomb for"
                        "explosion..." << endl;
                cout << "*KABOOM* You threw the bomb at the anchor's"
                        "chain, seperating it from the ship!" << endl;
                room[BOW].anchor = false;
            } else 
                cout << "You can't blow up anything in here." << endl;
        }

        if (player.bomb == false & player.knife == true 
              & player.flint == true) {
            cout << "You strike you knife against the flint creating a"
                    "small spark." << endl;
        }
    } else if (verb == "UNLOCK") {
        unlock(player, room, noun);
    } else if (verb == "USE") {
        use(player, room, noun);
    } else if (verb == "SAIL") {
        sail(player, room);
    } else if (verb == "CUT") {
        
        if (player.knife == true) {
            cut(player, room, noun);
        } else
            cout << "You do not have the means to cut anything." << endl;
    }
    
    else if (verb == "CRAFT"){
        if(player.gunpowder == true & player.cloth == true){
            cout<<"Using the cloth you make a little fuse for the pouch of\n"
                  "gunpowder; You made a bomb!"<<endl;
            player.bomb = true;
            player.cloth = false;
            player.pouch = false;
            player.gunpowder = false;
        }
        else cout<<"You don't have enough items to craft something."<<endl;
    }
    
    else if(verb == "HELP"){
                help();
    }            
    
    else if(verb =="MAP"){
        if(player.map == true) map();
        if(player.map == false) cout<<"You need a map first."<<endl;
    }
    
    else if(verb == "READ"){
        playerRead(player, room, noun);
    }
                        
    else if (verb == "INTRO"){
        intro();
    }
                
    else if (verb == "QUIT" or verb == "EXIT"){
        player.gamePlay = false;
    }
                
    else{
        cout << "\nI do not understand what you said." << endl;
    }
}    
        
void actionPath(Hero &heroStatus, Location room[]){
//actionPath is like a secondary main function. Instead of initializing everything, however, actionPath calls
//functions such as read and execute in order for the game to run.
//the other primary use of this function is to decide what happens when a certain direction is entered by the
//user, and whether there is a special instance that needs to occur
    
    Hero temp; // temporary holder of the heroStatus.curLoc

    if(room[heroStatus.curLoc].firstTime)
        description(heroStatus, room);
        
    read(heroStatus);
    execute(heroStatus, room);
    cout << endl;
                
    temp.curLoc = heroStatus.curLoc;
    
    if(heroStatus.userInput == "EAST"){
        heroStatus.curLoc = room[heroStatus.curLoc].east;
        
    }
            
    if(heroStatus.userInput == "WEST"){
        heroStatus.curLoc = room[heroStatus.curLoc].west;
        
        if(heroStatus.curLoc == SHORE and room[GANGPLANK].natives == true){    
            natives(heroStatus, room);
            heroStatus.curLoc = temp.curLoc;

// the logistics and aesthetics for when the player encounters the gorilla
void gorilla(Hero &player, Location room[]) {
    
    if (room[WHEEL].gorilla == true) {
        cout << "There is an agitated gorilla guarding the wheel.\n";
        cout << "He will not let you pass.\n";
        cout << endl;
    }    
}

// the logistics and aesthetics behind the verb cut
void cut(Hero &player, Location room[], string item) {
    
    if ((item == "BANANA" or item == "BANANAS") and player.knife == true) {
        cout << "\nCutting the bananas won't help you." << endl;
    } else if (room[BANANA_TREE].bananas == true 
                 and player.bananas == false and player.knife == true 
                 and item == "STEM"  and player.curLoc == BANANA_TREE) {
        cout << "\nYou have cut the stem and taken the bananas." << endl;
        player.bananas = true;
        room[BANANA_TREE].bananas = false;
        room[BANANA_TREE].longDescription = "There is a large banana tree"
                "here.\n"
                "You can see a beach to the north.";
    } else if (item == "CUT") {
        cout << "What would you like to cut?" << endl;
    } else
        cout << "\nThere is nothing for you to cut." << endl;
}
    
// the logistics and aesthetics behind the verb drop
void drop(Hero &player, Location room[], string item) {
    
    if (item == "KNIFE" and player.knife == true) {
        player.knife = false;
        room[player.curLoc].knife = true;
        cout << "\nDropped knife." << endl;
    } else if (item == "TREASURE" and player.treasure == true) {
        player.treasure = false;
        room[player.curLoc].treasure = true;
        cout << "\nDropped treasure." << endl;
    } else if (item == "KEYS" and player.keys == true) {
        player.keys = false;
        room[player.curLoc].keys = true;
        cout << "\nDropped keys." << endl;
    } else if (item == "BANANAS" and player.bananas == true) {
        if (player.curLoc == BANANA_TREE) {
            cout << "\nDropped bananas. A monkey quickly snatches them up"
                    "and runs\n";
            cout << "into the jungle." << endl;
            room[END].bananas = true;
            player.bananas = false;
        } else {        
            player.bananas = false;
            room[player.curLoc].bananas = true;
            cout << "\nDropped bananas." << endl;
        }    
    } else if (item == "BOTTLE" and player.bottle == true) {
        player.bottle = false;
        room[player.curLoc].bottle = true;
        cout << "\nDropped bottle." << endl;
    } else if (item == "POUCH" and player.pouch == true) {
        player.pouch = false;
        room[player.curLoc].pouch = true;
        cout << "\nDropped pouch." << endl;
    } else if (item == "BOMB" and player.bomb == true) {
        player.bomb = false;
        room[player.curLoc].bomb = true;
        cout << "\nDropped bomb." << endl;
    } else if (item == "GUNPOWDER" and player.gunpowder == true) {
        player.gunpowder = false;
        room[player.curLoc].gunpowder = true;
        cout << "\nDropped gunpowder." << endl;
    } else if (item == "FLINT" and player.flint == true) {
        player.flint = false;
        room[player.curLoc].flint = true;
        cout << "\nDropped flint." << endl;
    } else if (item == "CLOTH" and player.cloth == true) {
        player.cloth = false;
        room[player.curLoc].cloth = true;
        cout << "\nDropped cloth." << endl;
    } else if(item == "DROP") {
        cout << "\nWhat would you like to drop?" << endl;
        //fix so that you can just input the noun
    } else
        cout << "\nYou have nothing to drop." << endl;
}

//the logistics and aesthetics behind the verb eat
void eat(Hero &player, string item) {
    
    if ((item == "BANANAS" or item == "BANANA") 
           and player.bananas == true) {
        player.bananas = false;
        cout << "\nYou have eaten the bananas." << endl;
    } else if (item == "KEYS" and player.keys == true) {
        player.keys = false; 
        cout << "\nYou have eaten the keys. You'll regret that later..." 
             << endl;
    } else if (item == "KNIFE" and player.knife == true) {
        player.knife = false;
        cout << "\nYou have eaten the knife.\n" << endl;
        cout << "Your internal organs have been punctured and you die of" 
             << "internal bleeding" << endl
             << "and organ failure." << endl;
        player.gamePlay = false;
    } else if (item == "TREASURE" and player.treasure == true) {
        player.treasure = false;
        cout << "\nYou have eaten the treasure.\n" << endl;
    } else if (item == "POUCH" and player.pouch == true) {
        player.pouch = false;
        cout << "\nYou have eaten the pouch.\n" << endl;
    } else if (item == "BOTTLE" and player.bottle == true) {
        player.bottle = false;
        cout << "\nYou have eaten the bottle.\n" << endl;
        cout << "Your internal organs have been punctured and you die of"
             << "internal bleeding" << endl;
        cout << "and organ failure." << endl;
        player.gamePlay = false;
    } else if (item == "FLINT" and player.flint == true) {
        player.flint = false;
        cout << "\nYou have eaten the flint.\n" << endl;
    } else if (item == "GUNPOWDER" and player.gunpowder == true) {
        player.gunpowder = false;
        cout << "\nYou have eaten the gunpowder.\n" << endl;
    } else if(item == "CLOTH" and player.cloth == true) {
        player.cloth = false;
        cout << "\nYou have eaten the cloth.\n" << endl;
    } else 
        cout << "\nYou have nothing to eat." << endl;
    }
    
// the logistics and aesthetics behind the verb give
void give(Hero &player, Location room[], string item) {
    
    if ((item == "BANANAS" or item == "BANANA") and player.bananas == true 
           and player.curLoc == PATHWAY) {
        room[WHEEL].gorilla = false;
        player.bananas = false;
        cout << "\nThe gorilla aggresively grabs the bananas and leaves"
             << "the ship." << endl;
    } else if(item == "TREASURE" and player.treasure == true 
                and player.curLoc == GANGPLANK) {
         room[GANGPLANK].natives = false;
         player.treasure = false;
         cout << "\nThe natives graciously accept your gift and leave the"
              << "shore." << endl;
    } else {
        cout << "\nYou can't give that." << endl;
    }
}

// the logistics and aesthetics behind the verb destroy
void destroy(Hero &player, string item) {
    if ((item == "BANANAS" or item == "BANANA") 
           and player.bananas == true) {
        cout << "\nYou have destroyed your bananas." << endl;
        player.bananas = false;
    } else if (item == "KNIFE" and player.knife == true) {
        cout << "\nYou have destroyed your knife." << endl;
        player.knife = false;
    } else if (item == "KEYS" and player.keys == true) {
        cout << "\nYou have destroyed your keys." << endl;
        player.keys = false;
    } else if (item == "TREASURE" and player.treasure == true) {
        cout << "\nYou have destroyed your treasure." << endl;
        player.treasure = false;
    } else if (item == "MAP" and player.map == true) {
        cout << "\nYou have destroyed your map." << endl;
        player.map = false;
    } else if (item == "BOTTLE" and player.bottle == true) {
        cout << "\nYou have destroyed your bottle." << endl;
        player.bottle = false;
    } else if (item == "POUCH" and player.pouch == true) {
        cout << "\nYou have destroyed your pouch." << endl;
        player.pouch = false;
    } else if (item == "FLINT" and player.flint == true) {
        cout << "\nYou have destroyed your flint." << endl;
        player.flint = false;
    } else if (item == "GUNPOWDER" and player.gunpowder == true) {
        cout << "\nYou have destroyed your gunpowder." << endl;
        player.gunpowder = false;
    } else if (item == "BOMB" and player.bomb == true) {
        cout << "\nYou have destroyed your bomb." << endl;
        player.bomb = false;
    } else if (item == "CLOTH" and player.cloth == true) {
        cout << "\nYou have destroyed your cloth." << endl;
        player.cloth = false;
    } else if(item == "DESTROY") {
        cout << "\nWhat would you like to destroy?" << endl;
    } else {
        cout << "\nYou have no such item to destroy." << endl;
    }
}
    
/*
    the logistics and aesthetics behind the verb sail includes the final
    text for when the player wins the game
*/
void sail(Hero &player, Location room[]) {
    
    string decision;
    

    if (player.curLoc == WHEEL) {
        if (player.win == true and room[BOW].anchor == false) {
            cout << "\nPRISONER: 'Let's do this!'\n";
        if (player.treasure == true) {
            cout << "PRISONER: 'We can live off our treasures for the rest"
                    "of our lives mate!'\n";
        if (player.treasure == false) { 
            cout << "PRISONER: 'Its a shame you gave our treasure away to" 
                    "those natives!'\n";
            cout << endl;
            player.gamePlay = false;
            cout << "CONGRATULATIONS!!!" << endl;
            cout << "YOU HAVE WON!!!" << endl;
        } else if (player.win == true and room[BOW].anchor == true) {
            cout << "\nPRISONER: 'The Ol' ship still be attached to the"
                    "shore!\n";
        }
    } else if (player.curLoc == WHEEL and player.win == false) {
        cout << "\nYou are unable to sail the ship on your own." << endl;
        cout << "You will need to find another way." << endl;
    }
}

// the logistics and aesthetics behind the verb search
void search(Hero &player, Location room[]) {
    
    cout << "\nThese items may be of interest:\n";

    if (room[player.curLoc].keys == true) {
        cout << "A set of keys" << endl;
    }    
                    
    if (room[player.curLoc].knife == true) {
        cout << "A sturdy knife" << endl;
    }
    
    if (room[player.curLoc].map == true) {
        cout<< "A map of the ship" << endl;
    }
                    
    if (room[player.curLoc].bananas == true) {
        cout << "A bunch of bananas" << endl;
    }
                    
    if (room[player.curLoc].treasure == true) {
        cout << "A bunch of valuable treasures" << endl;
    }
    
    if (room[player.curLoc].bottle == true) {
        cout << "A message in a bottle" << endl;
    }
    
    if (room[player.curLoc].pouch == true) {
        cout << "A large pouch" << endl;
    }
    
    if (room[player.curLoc].gunpowder == true) {
        cout << "Lots of gunpowder" << endl;
    }
    
    if (room[player.curLoc].flint == true) {
        cout<<"A chunk of flint"<< endl;
    }
    
    if (room[player.curLoc].bomb == true) {
        cout<<"A dangerous bomb"<< endl;
    }
    
    if (room[player.curLoc].cloth == true) {
        cout<<"A large piece of cloth"<< endl;
    } else
        cout << "\nYou stop searching..." << endl;
}

// the logistics and aesthetics behind the verb take
void take(Hero &player, Location room[], string item){
    
    if (item == "KNIFE" and room[player.curLoc].knife == true) {
        player.knife = true;
        room[player.curLoc].knife = false;
        room[CAP_QTR].longDescription = "There is a bed with a nightstand"
            "here. In the middle of the room, there is a\n"
            "navigational table with a map.\n";
        cout << "\nKnife taken" << endl;
    } else if (item == "TREASURE" or item == "TREASURES" 
                 and room[player.curLoc].treasure == true) {
        player.treasure = true;
        room[player.curLoc].treasure = false;
        cout << "\nTreasure taken." << endl;
    } else if (item == "KEYS" and room[player.curLoc].keys == true) {
        player.keys = true;
        room[player.curLoc].keys = false;
        room[CAP_QTR].longDescription = "There is a bed with a nightstand"
            "here. In the middle of the room, there is a\n"
            "navigational table with a map.\n";
        cout << "\nKeys taken." << endl;
    } else if (item == "BANANAS" and room[player.curLoc].bananas == true) {
        if (room[BANANA_TREE].bananas == true) {
            cout << "You cannot break the stem with your barehands." 
                 << endl;
        } else {
            player.bananas = true;
            room[player.curLoc].keys = false;
            cout << "\nBananas taken" << endl;
        }
    } else if (item == "BOTTLE" and room[player.curLoc].bottle == true) {
        player.bottle = true;
        room[player.curLoc].bottle = false;
        cout << "\nBottle taken." << endl;
    } else if (item == "POUCH" and room[player.curLoc].pouch == true) {
        player.pouch = true;
        room[player.curLoc].pouch = false;
        cout << "\nPouch taken." << endl;
    } else if (item == "MAP" and room[player.curLoc].map == true) {
        player.map = true;
        room[player.curLoc].map = false;
        cout << "\nMap taken." << endl;
    } else if (item == "GUNPOWDER" 
                 and room[player.curLoc].gunpowder == true) {
        if (player.pouch == false) {
            cout << "You need something to hold the gunpowder in." << endl;
        }

        if (player.pouch == true) {
            player.gunpowder = true;
            player.pouch = false;
            cout << "You take the gunpowder and put in inside the pouch." 
                 << endl;
        }
    } else if (item == "CLOTH" and room[player.curLoc].cloth == true) {
        player.cloth = true;
        room[player.curLoc].cloth = false;
        cout << "\nCloth taken." << endl;
    } else if (item == "BOMB" and room[player.curLoc].bomb == true) {
        player.bomb = true;
        room[player.curLoc].bomb = false;
        cout << "\nBomb taken." << endl;
    } else if (item == "FLINT" and room[player.curLoc].flint == true) {
        player.flint = true;
        room[player.curLoc].flint = false;
        cout << "\nFlint taken." << endl;
    } else if (item == "TAKE") {
        cout << "\nWhat would you like to take?" << endl;
    } else
        cout << "\nThere is no such item here." << endl;
    }

// the logistics and aesthetics behind the verb unlock
void unlock(Hero &player, Location room[], string item) {
    
    if (player.keys == true and player.curLoc == BRIG 
          and room[PATHWAY].gorilla == false and (item == "PRISON" 
          or item =="DOOR" or item == "UNLOCK" or item == "CELL")) {
        cout << "\nYou were able to unlock the cell with your key.\n" 
             << endl;
        cout << "PRISONER:'Thanks, mate! Best we meet at the wheel. I'll"
             << "be waiting to set sail.\n";
        player.win = true;
        room[WHEEL].firstTime = true;
        room[WHEEL].longDescription = "You see the wheel that steers the"
            "ship.\n"
            "Although you hardly remember anything, the prisoner can help"
            "you steer the ship\n"
            "and sail to freedom.";
    } else if (player.keys == true and player.curLoc != BRIG) {
        cout << "\nThere is nothing to use your key on." << endl;
    } else if (player.keys == true) {
        cout<< "\nYou don't have any keys."<< endl;
    } else {
        cout << "\nThere is nothing to unlock." << endl;
    }
}

// I dont like this function
// he logistics and aesthetics behin the verb use
void use(Hero &player, Location room[], string item) {       

    if (player.map == true && item == "MAP") {
        cout << endl;
        map();
    }
    
/*  else if (player.spyglass == true and player.curLoc == CROWS_NEST) {
        cout << "You can see the entire island from here. In addition to"
             << "the shore and ship,\n"
             << "there appears to be small village west of the banana" 
             << "tree.\n";
    }
*/    
    else if (player.knife == true & item == "KNIFE") {
        cout << "I can use this with flint if I had some..." << endl;
    } else if (player.keys == true) {
        if (player.curLoc == BRIG and room[PATHWAY].gorilla == false) {
            cout << "\nYou were able to unlock the cell with your key.\n" 
                 << endl;
            cout << "PRISONER:'Thanks, mate! Best we meet at the wheel." 
                 << "I'll be waiting to set sail.\n";
            player.win = true;
            room[WHEEL].firstTime = true;
            room[WHEEL].longDescription = "You see the wheel that steers" 
                "the ship.\n"
                "Although you hardly remember anything, the prisoner can"
                "help you steer the ship\n"
                "and sail to freedom.";
            } else
                cout << "\nThere is nothing to use your key on." << endl;
    } else if (player.bananas == true) {
        cout << "The only use this has is for consumption or bartering..." 
             << endl;
    } else if (player.treasure == true) {
        cout << "How would you like to use the treasure?" << endl;
    } else if (player.map == true) {
        cout << "How would you like to use the map?" << endl;
    } else if (item == "USE") {
        cout << "\nWhat would you like to use?" << endl;
    } else
        cout<<"\nI don't know what you are trying to do?"<< endl;
    
}

void map(){
    cout << endl;
    cout << "|-----------------------------------------------------------"
         << "---------|\n";
    cout << "|        UP              Ye Ol' Ship's Layout               "
         << "         |\n";
    cout << "| SOUTH<-->NORTH                                            "
         << "         |\n";
    cout << "|      DOWN                  [CROWS NEST]                   "
         << "         |\n";
    cout << "|                            ____________                   "
         << "         |\n";
    cout << "|                                |||                        "
         << "         |\n";
    cout << "|   |  [WHEEL]                   |||                        "
         << "         |\n";
    cout << "|   |_________________           |||                        "
         << "         |\n";
    cout << "|   |[CAPTAIN QUARTER][STAIRS][TOP DECK]        [BOW]       "
         << "    /    |\n";
    cout << "|   |_______________________________________________________"
         << "___/     |\n";
    cout << "|   |[LIVING QUARTER]       [BOTTOM DECK] [INFIRMARY]" 
         << " [GALLEY]/      |\n";
    cout << "|   |_______________________________________________________"
         << "_/       |\n";
    cout << "|   |[BRIG]                    [CARGO]         [ARMORY]     "
         << "/        |\n";
    cout << "|   |______________________________________________________/"
         << "         |\n";
    cout << "|-----------------------------------------------------------"
         << "---------|\n";
    cout << endl;
}

void help() {
    cout << "MOVEMENT COMMANDS:" << endl;
    cout << "'NORTH' or 'n' to move north" << endl;
    cout << "'EAST' or 'e' to move east" << endl;
    cout << "'SOUTH' or 's' to move south" << endl;
    cout << "'WEST' or 'w' to move west" << endl;
    cout << "'DOWN' or 'd' to move down" << endl;
    cout << "'UP' or 'u' to move up" << endl;
    cout << endl;
    cout << "USEFUL COMMANDS:" << endl;
    cout << "'INVENTORY' - show items in inventory" << endl;    
    cout << "'SEARCH' - search room for items" << endl;    
    cout << "'TAKE' - take items from room" << endl;
    cout << "'DROP' - drop items from inventory" << endl;
    cout << "'LOOK' - show full room description" << endl;
    cout << "'GIVE' - give an item" << endl;
    cout << "'EAT' - eat an item" << endl;
    cout << "'CUT' - cut an object or item" << endl;
    cout << "'UNLOCK' - unlock an object or item" << endl;
    cout << "'SAIL' - to sail the ship" << endl;
    cout << endl;
    cout << "'QUIT' - ends the game" << endl;
    cout << "------------------------------------------------------------"
         << "------------------";
}

/*
    this function takes the string spoken to the parrot and translates it
    into pig latin. by splitting the string into individual words, each
    word can then be altered to look and sound like pig latin
*/ 
void pigLatin(Hero &player, Location room[]) {
    
    string input;
    string hello, polly, cracker;
    string word, front, verb;
    string ay;
            
    cout << "\nYou feel an intense power come over you...\n";
    cout << "You no longer have control of yourself.\n\n";
    cout << "'SQUAWK! What's the secret phrase? SQUAWK!'\n";
            
    while (verb != "TALK") {
        cout << "'SQUAWK! SQUAWK! SQUAWK!'\n\n"; 
        cout << "It seems your only option is to TALK to the parrot and" 
             << "tell her the right words." << endl;
        
        read(player);
        verb.assign(player.userInput,0,player.userInput.find(" "));
            
        for (int i=0; i < verb.length(); i++) {
            verb[i]=toupper(verb[i]);
        }
    }

    while (room[CAP_QTR].keys == false) {
        cout << "\nWhat do you want to say to the bird?" << endl;
        cout << endl;
        cout << ">>";
        getline(cin,input);
        cout << endl;
        
        cout << setfill('-') << setw(80)<< "-" << endl;
        cout << endl;
        
        if (input.find(" ") == 0)
            input.erase(0,1);
        
        if (input.find(" ") == input.length()-1)
            input.erase(input.length()-1, 1); 
        
        if (input.find("hello") != -1 or input.find("polly") != -1 
              or input.find("cracker") != -1) {

            cout << "'SQUAWK! Captain's Quarters! Secret Compartment!" 
                 << " Keys to Brig! SQUAWK!'" << endl;
            room[CAP_QTR].keys = true;
            room[CAP_QTR].firstTime = true;
            if (room[CAP_QTR].knife == true) {
                room[CAP_QTR].longDescription = "There is a bed with a" 
                    "nightstand here. In the middle of the room, there is"
                    "a\n"
                    "navigational table with a map. On the nightstand," 
                    "there appears to be a\n"
                    "large knife.\n"
                    "\nYou now also see the secret compartment housing" 
                    "the keys to the brig.";
            } else if (room[CAP_QTR].knife == false) {
                room[CAP_QTR].longDescription = "There is a bed with a" 
                    "nightstand here. In the middle of the room, there is" 
                    "a\n"
                    "navigational table with a map.\n"
                    "\nYou now also see the secret compartment housing" 
                    "the keys to the brig.";
            }
        } else {
            cout << "Parrot: ";
            while (input.empty() != true) {
                if (input.find(" ") == 0)
                    input.erase(0,1);
                    
                word = input.substr(0, input.find(" "));
                
                if (input.find(" ")== -1) {
                    word = input;
                    input.clear();
                }

                if (word[0] == 'a' or word[0] == 'e' or word[0] == 'i' 
                      or word[0] == 'o' or word[0] == 'u') {
                    
                    word.append("way");
                    
                } else if (word.substr(0,2) == "th" 
                             or word.substr(0,2) == "ch" 
                             or word.substr(0,2) == "sh" 
                             or word.substr(0,2) == "ph" 
                             or word.substr(0,2) == "wh" 
                             or word.substr(0,2) == "qu" ) {
                        
                    front = word.substr(0,2);
                    word.erase(0,2);
                    word.append(front + "ay");
                } else {
                    front = word[0];
                    word.erase(0,1);
                    word.append(front +"ay");
                }
                
                cout << word << " ";
                input.erase(0, input.find(" ")+1);    
            }
        }
        cout << endl;
    }
}

void playerRead(Hero &player, Location room[], string item) {
    if (item == "MAP" & player.map == true)
        map();
    else if ((item == "MESSAGE" or item == "BOTTLE") 
                  & player.bottle == true) {
        cout << "A text based adventure game for CSCI 40:\n"
                "For movement and other useful commands type HELP.\n"
                "Not all commands are listed and may require verb +" 
                " noun.\n"
                "Good luck!\n";    
    } else 
        cout << "I don't know what you are trying to read?" << endl;
}
