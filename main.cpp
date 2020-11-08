#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <array>
#include <sstream>
using namespace std;

void showStats(int charisma, int strength, int constitution, int intelligence, int wisdom, int dexterity) {
  //shows user stats
  cout << "Here are your current stats: " << endl;
  cout << "Charisma: " << charisma << endl;
  cout << "Strength: " << strength << endl;
  cout << "Constitution: " << constitution << endl;
  cout << "Intelligence: " << intelligence << endl;
  cout << "Wisdom: " << wisdom << endl;
  cout << "Dexterity: " << dexterity << endl;
} 

string userNext(string userInput) {
  //user input changes to 'Next'
  if (userInput != "Next")  {
    for (int i = 0; i < userInput.size(); ++i) {
      userInput.at(i) = tolower(userInput.at(i));
    }
    userInput.at(0) = toupper(userInput.at(0));
  }
  return userInput;
}

string whileNotNext(string userInput) {
  while(userInput != "next" && userInput != "Next" && userInput != "NEXT") {
  cin.clear();
  cin.ignore();
  cout << "Type in 'Next' to continue"<<endl;
  cin >> userInput;
  }

 return userInput;
}
int dieRoll(int diceResult) {
  srand(time(0));
  diceResult = (rand() % 10) + 1;

  return diceResult;
}
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}
   

int main() {
  int userInt, checkTask, taskInt, diceResult, untilLunchBreak = 0;
  string userInput, userName, chosenTask;
  int decisionNumber;
  int successNumber = 0;
  bool unfinishedTasks = true;
  srand(time(0));
  //stats, out of 10
  // (rand() %  10 ) + 1; 
  int charisma = 1, strength = 1, constitution = 1, intelligence = 1, wisdom = 1, dexterity = 1, performanceScore = 0;
  string statsType[6]= {"Charisma", "Strength", "Constitution", "Intelligence", "Wisdom", "Dexterity"}; //6 constant strings or whatever
  int statsList[6] = {1, 1, 1, 1, 1, 1}; 

  string taskList[6] = {"Mob Control", "Move Shopping Carts", "Do Computer Work", "Stock Items in Storage", "Work at Cash Register", "Clean Bathrooms"};
  int taskListSize = sizeof(taskList) / sizeof(string);

  cout << "It was a cold rainy morning... " << endl;
  cout << "Your phone alarm wakes you up." << endl;
  cout << "You reach for it to turn it off." << endl;
  cout << "It reads 'Target Shift'" << endl;
  cout << "You brush your teeth and change into your red Target uniform." << endl;
  cout << "Time to head to work! (Type in 'Next' to continue)" << endl;
  cin >> userInput;

  userInput = whileNotNext(userInput); //This will ask to text next.

  userInput = userNext(userInput); //this will return as 'Next'

  cout << endl;
 
   /* add a while loop after the if statement for asking the user to type next because they did it wrong */


  //worker enters the Target
  cout << "You arrive at the Target." << endl;
  cout << "You go to the computer to check in." << endl;
  cout << "A pop-up message prompts you to enter in your name." << endl; 
  cout << "Type in your Name: " << endl;
  getline(cin, userName);
  getline(cin, userName);
  
  cout << endl;

  //stats appear
  showStats(charisma, strength, constitution, intelligence, wisdom, dexterity); 
  cout << "You must achieve a score greater than 6 on a check to succeed. This is determined via a roll of a ten sided dice, along with your modifier for a check. For example, if you do a dexterity action, then you add your dexterity bonus to a roll to help you succeed." << endl;

  cout << "Type 'Next' to continue: " << endl;
  cin >> userInput;
  userInput = whileNotNext(userInput); //This will ask to text next.
  userInput = userNext(userInput);

  cout << endl;
  
  cout << "Good morning, " << userName << "." << endl;
  cout << "After all tasks are done, your performance will be shown." << endl;
  cout << "Today, you will do 6 tasks throughout the day." << endl;
  cout << "You do not have to do your tasks in order." << endl;
  cout << "Type 'Next' to continue: " << endl;
  cin >> userInput;

  userInput = whileNotNext(userInput); //This will ask to text next.
  userInput = userNext(userInput);

  cout << endl;
  
  while (untilLunchBreak < 6) {
    //lunchBreak, after three tasks are done
    
    if (untilLunchBreak == 3) {
      //lunch break heck yeah
      cout << "Now, before you continue your tasks, it's time for your lunch break!" << endl;
      cout << "You head to the Starbucks at the front of the store." << endl;
      cout << "What would you like to order?" << endl;
      cout << "1. Crispy Grilled Cheese Sandwich" << endl;
      cout << "2. Turkey & Basil Pesto Sandwich" << endl;
      cout << "3. Peanut Butter & Jam Protein Box" << endl;
      cout << "4. Cheese & Fruit Protein Box" << endl;
      cout << "5. Chicken & Quinoa Protein Bowl" << endl;
      cin >> userInt;

      while (userInt <= 0 || userInt > 5) {
        cout << "Please enter a valid meal number: " << endl;
        cin >> userInt;
      }
      
      //starbucks barista giving you dirty eyes if your successfulNum is low

      if (userInt == 1) {
        cout << "You take a bite into your crispy grilled cheese sandwich." << endl;
      }
      else if (userInt == 2) {
        cout << "You take a bite into your turkey and basil pesto sandwich." << endl; 
      }
      else if (userInt == 3) {
        cout << "You open up your peanut butter & jam protein box." << endl;
      }
      else if (userInt == 4) {
        cout << "You open up your cheese and fruit protein box." << endl;
      }
      else if (userInt == 5) {
        cout << "You dig into your chicken and quinoa protein bowl." << endl;
      }

      cout << "Type 'Next' to continue: "; 
      cin >> userInput;
      userInput = whileNotNext(userInput); //This will ask to text next.
      userInput = userNext(userInput);

      cout << "As you are eating, you think about the tasks you've done so far, and how much you would like to go home already." << endl;
      cout << "Here is how well you are doing right now: ";
      showStats(charisma, strength, constitution, intelligence, wisdom, dexterity);
      
      cout << "You have " << successNumber << " successful tasks. You need at least 3 successful tasks to not get fired." << endl;

      cout << "Type 'Next' to continue: ";
      cin >> userInput;
      userInput = whileNotNext(userInput); //This will ask to text next.
      userInput = userNext(userInput);
    }
   

  //user chooses the task
    cout << "Here are your current tasks: " << endl;
    for (int i = 0; i < taskListSize; ++i) {
      cout << i + 1 << ". "<< taskList[i] << endl;
    }

    cout << endl << "Please choose your task: ";
    while (true){
      string userInput;
      cin >> userInput;
      if (isNumber(userInput)){
        userInt = stoi(userInput);
        break;
      }
      else{
        cout << "Please enter a number between 1 & 6:   ";
      }
    }
    
    //(taskList[userInt - 1] == "Completed Task")
    while ((userInt <= 0) || (userInt > 6)|| (taskList[userInt - 1] == "Completed Task") )/* ERROR HERE */ {
      cout << "Please choose a valid task. ";
      cin >> userInt;
      userInt = 
    }
    
    taskInt = userInt;
    taskList[userInt - 1] = "Completed Task"; 


  if (taskInt == 1) {
    //mob Control
    ++untilLunchBreak;
    cout << "Mob control: " << endl;
    cout << endl;
    cout << "While going about your standard routine you gain +2 wisdom." << endl;
    wisdom += 2;
    cout << "Wisdom points: " << wisdom << endl;
    cout << endl;
    cout << "Decision Event: There's a big electronics sale going on. Suddenly, a mob of customers come rushing into the store to try to loot everything!" << endl;
    diceResult = dieRoll(diceResult);
    cout << "Choose an option (1, 2, or 3) to resolve this conflict" << endl;

    cout << "1) Hold them back using only your massive pecs (strength test)" << endl;
    cout << "2) Action roll between them to avoid being trampled (dexterity test)" << endl;
    cout << "3) Tear off your shirt and blend in among the crowd (wisdom test)"<< endl;

    cin >> decisionNumber;
    while ((decisionNumber != 1)&&(decisionNumber != 2)&&(decisionNumber != 3)) {
      cout << "Please enter 1, 2, or 3" << endl;
      cin >> decisionNumber;
    }

    if (decisionNumber == 1) {
      diceResult = diceResult + strength;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: There is no way for any amount of bodies to break through your perfect defense, as abs upon abs block the mob from causing any unnecessary havoc." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: Overconfidence is a menace, and you clearly overestimate your body's strength. Some guy sucker punches you to the ground, allowing the mob to wreak chaos in the store. All the while you just lay on the floor. Like a baby." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 2) {
      diceResult = diceResult + dexterity;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: Like a Dark Souls master, it doesn't matter what is thrown at you as long as you can perfectly action roll. You bob and weave throughout the crowd, keeping you alive." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You try to action roll through the crowd when you immediately have your spine stomped on mid-roll. The mob just walks over your screaming body." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 3) {
      diceResult = diceResult + wisdom;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: Taking off your uniform and throwing on a black hoodie from the clothes aisle, you blend in among the crowd, but also attempt to divert the crowd away from the store into the Walmart next door..." << endl;
        cout << " " << endl;
        cout << "...and it works! The crowd is aware of your presence and follows the person who shouts the most. Now the rival store has your problem to worry about." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE:  Taking off your uniform and throwing on a black hoodie from the clothes aisle, you blend in among the crowd, but also attempt to divert the crowd away from the store into the Walmart next door..." << endl;
        cout << "" << endl;
        cout << "...and instantly get beaten up. Somebody forgot to take off their Target employee lanyard, and stood out like a sore thumb in the crowd as an anti-mob figure." << endl;
        cout << "" << endl;
      }
    }



  }
  else if (taskInt == 2) {
    //move shopping carts
    ++untilLunchBreak;
    cout << "Shopping Carts: " << endl;
    cout << endl;
    cout << "From moving shopping carts in the parking lot, you gain +2 dexterity." << endl;
    dexterity += 2;
    cout << "Dexterity points: " << dexterity << endl;
    cout << endl;
    cout << " Decision Event: You spot a granny walking outside from the store towards her car when a speeding car comes into view!" << endl;
    diceResult = dieRoll(diceResult);
    cout << "Choose an option (1, 2, or 3) to resolve this conflict" << endl;

    cout << "1) Try to use a bunch of linked shopping cars to ram the car before it can hit the old lady (strength test)" << endl;
    cout << "2) Try to do a 'high speed scoop up' of the old lady in one of the shopping carts (dexterity test)" << endl;
    cout << "3) The lady looks a lot like Margaret Thatcher. Let the car hit her (intelligence test)" << endl;

    cin >> decisionNumber;
    while ((decisionNumber != 1)&&(decisionNumber != 2)&&(decisionNumber != 3)) {
      cout << "Please enter 1, 2, or 3" << endl;
      cin >> decisionNumber;
    }

    if (decisionNumber == 1) {
      diceResult = diceResult + strength;
      cout << "You got a " << diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS:You run your shopping cart into several others, locking them into place, until you have a literal battering ram. The car comes quickly and, getting closer to the lady..." << endl; 
        
        cout << "gets t-boned by your battering ram of shopping carts and flies into the street, rolling over several times before exploding like a Michael Bay movie. The old lady thanks you for your service, leading to a good newspaper story promoting the store and its employees." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "You run your shopping cart into several others, locking them into place, until you have a literal battering ram. The car comes quickly and, getting closer to the lady..." << endl;
 
        cout << "hits her. The lady goes flying out of existence, the car speeding off blaring A7X, and your shopping cart battering ram hits a parked car after missing, in which you spend time buffing out the dent." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 2) {
      diceResult = diceResult + dexterity;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS:You start to get speed while running your cart towards the old lady. Hitting 60, no 70, no, 88 MILES PER HOUR!" << endl;
 
       cout << "At the last second you point the nose down, scoop the old lady up, and travel back in time right as the car was about to hit you." << endl;
 
       cout << "You appear seconds before the accident took place near the store with the old lady. She is busy thanking you when this timeline's version of the old lady gets hit by the car and flies away. The police are left in confusion at the both dead and alive old lady, but at least one of them is safe." << endl;
       cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "You start to get speed while running your cart towards the old lady. Hitting 60, no 70, no, 88 MILES PER HOUR!" << endl;
 
       cout << "FAILURE: And then you hit the lady going 88 miles per hour. She didn't go into the cart but rather got stuck to the front of the vehicle as both you and her slam into a wall. You may be a mess, but the old lady just had an instantaneous funeral and burial into a brick wall." << endl;
       cout << "" << endl;
      }
    }
    else if (decisionNumber == 3) {
      diceResult = diceResult + intelligence;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: You think that the old lady looks exactly like Margaret Thatcher and, knowing how much of a pain she is, do nothing to prevent the car from hitting her." << endl;
 
       cout << "The police admire you for your efforts and the manager as well! Apparently Margaret Thatcher has been revived and talking about retaking England, so it's good that you put a stop to it." << endl;
       cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "You think that the old lady looks exactly like Margaret Thatcher and, knowing how much of a pain she is, do nothing to prevent the car from hitting her." << endl;
 
        cout << "FAILURE: You realize after you find the body that it was not, shockingly, Ms. Thatcher. What a twist. You make up an excuse to the manager to hide the old lady before anyone notices, and lose work time." << endl;
        cout << "" << endl;
      }
    }





    


  }
  else if (taskInt == 3) {
    //Do Computer Work
    ++untilLunchBreak;
    cout << "Computer Work:" << endl;
    cout << endl;
    cout << "Working on the local branch’s company site granted you +2 intelligence!" << endl;
    intelligence += 2;
    cout << "Intelligence points: " << intelligence << endl;
    cout << endl;
    cout << "Decision Event: An Indian hacker attempts to send a virus to the local computer due to a security fault!" << endl;
    diceResult = dieRoll(diceResult);
    cout << "Choose an option (1, 2, or 3) to resolve this conflict" << endl;

    cout << "1) Unplug and replug the computer (wisdom)" << endl;
    cout << "2) Work through the virus to temporarily shut down the site (constitution)" << endl;
    cout << "3) Try to plug the security hole so the virus doesn’t fully transfer (intelligence)" << endl;

    cin >> decisionNumber;
    while ((decisionNumber != 1)&&(decisionNumber != 2)&&(decisionNumber != 3)) {
      cout << "Please enter 1, 2, or 3" << endl;
      cin >> decisionNumber;
    }

    if (decisionNumber == 1) {
      diceResult = diceResult + wisdom;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: You quickly try to unplug the computer before the virus fully transfers, but make sure to get the save state out via an external hard drive before something happens to it. After rebooting and restoring the PC, you have saved the branch from a large amount of sudden data loss, which your manager is grateful for." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You quickly try to unplug the computer before the virus fully transfers. After all, if it doesn’t work, try turning it off and on again. However, you turn on the computer and the virus keeps installing! After burning down the computer before any major data gets stolen, you are berated by the manager for your failure to realize what the external drive was for, as well as your overreaction. By burning the PC down." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 2) {
      diceResult = diceResult + constitution;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: The virus has already started deploying, putting out screen-blocking adds to stop you from interfering with the final download. But you trail on, clicking through close button after close button, and finally manage to get to the main page to cancel the transfer." << endl;
        cout << "" << endl;
        
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: The virus has already started deploying, putting out screen-blocking adds tostop you from interfering with the final download. You try to get through every obscene and scam-obvious add, but before long you are overcome by an infinite number of adds, as you watch your software slowly rot away with the data loss." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 3) {
      diceResult = diceResult + intelligence;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: After a tedious process of both utilizing the antivirus software and workingon the site’s securities, you manage to finally cut the constant installation of the virus and save the data that would otherwise be lost to somebody mysterious…" << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You try to patch the security holes on the website to stop the transfer, but aren’t smart enough to just come up with an easy solution. Eventually you succumb to the realization of your demise as the files have been stolen during your slow work. You lose a lot of work time just attempting to save something..." << endl;
        cout << "" << endl;
      }
    }


  }
  else if (taskInt == 4) {
    //Stock Items in Storage
    ++untilLunchBreak;
    cout << "Stocking Items:" << endl;
    cout << endl;
    cout << "You tirelessly stocked items in the storage room, gaining +2 strength as a result." << endl;
    strength += 2;
    cout << "Strength points: " << strength << endl;
    cout << endl;
    cout << "Decision Event: Oh No! Your coworker Chantal gets stuck on the top rack of a shelf!" << endl;
    diceResult = dieRoll(diceResult);
    cout << "Choose an option (1, 2, or 3) to resolve this conflict" << endl;
    cout << "1) try to parkour between the rack that the employee is stuck on and the opposite rack (dexterity test)" << endl;
    cout << "2) instruct the employee on how to get down (charisma test)" << endl;
    cout << "3) try to use the remainder of the broken ladder to get down to the lower part of the opposing rack to get down (wisdom test)" << endl;

    cin >> decisionNumber;
    while ((decisionNumber != 1)&&(decisionNumber != 2)&&(decisionNumber != 3)) {
      cout << "Please enter 1, 2, or 3" << endl;
      cin >> decisionNumber;
    }


    if (decisionNumber == 1) {
      diceResult = diceResult + dexterity;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: You quickly grab from one rack to another higher rack on the opposing time with some rope in your hand until you reach the employee, being fast enough not to topple either rack storages. You use the rope to help the employee climb down, and save some time possibly waiting for other help to get him." << endl;   
        cout << "" << endl;   
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You attempt to backflip onto one rack and then jump to a higher opposing rack, but on the backflip you hit your head on one of the rack platforms. This ironically causes the employee to fall from rack to rack and eventually on top of you. While she is safe, you suffer some injuries and have to work through the pain during your shift." << endl;
        cout << "" << endl;
    }
  }
     
    else if (decisionNumber == 2) {
      diceResult = diceResult + charisma;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: You instruct the employee to get down on the far side of the rack not facing the opposite direction, and your commanding confidence inspires him to overcome the dangers of being at that height. You tell him the exact points to grab on his way down so he doesn’t topple the rack, and watch him safely recover at the bottom. You saved the company a lot of time and money trying to get him back down!" << endl; 
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "YFAILURE: ou try to instruct the employee to get down on the side of the rack, but when he does it starts to topple over; he just barely reaches back to not completely fall down, and will now not listen to anybody. You call the fire department to finally get him down later but wasted a lot of time in doing so." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 3) {
    diceResult = diceResult + wisdom;  
    cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: You know that using the ladder could work to get him, but with the other side broken off you will have to climb up the pole of the ladder to get to him. It would probably slip off the ground if you placed it there, but you find a sturdy clamp nearby, and instead use it on one of the lower opposite racks to make the ladder diagonal, and less likely to slip with it being pushed into the clamp and supported by the rack. You wiggle up with some rope to help the employee climb down, and save some time possibly waiting for other help to get him." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You know that using the ladder could work to get him, but with the other side broken off you will have to climb up the pole of the ladder to get to him. You place it on the ground, but aren’t wise enough to see that it might slip with force given to it. After climbing ever so close to the rack and the employee, it gives way and you watch as you slam to the floor. Now you have to work your shift with an injury..." << endl;
        cout << "" << endl;
      }
    }


    

  }
  else if (taskInt == 5) {
    //Work at Cash Register
    ++untilLunchBreak;
    cout << "Cash Register:" << endl;
    cout << endl; 
    cout << "Manning cash register and talking to customers bolstered your charisma by +2." << endl; 
    charisma += 2;
    cout << "Charisma points: " << charisma << endl;
    cout << endl;
    cout << "Decision Event: a wild Karen enters the Target screaming with great fury. The beast is upset because she bought 3 jeans that were labeled as blue jeans when they were 'dark blue'." << endl;
    diceResult = dieRoll(diceResult);
    cout << "Choose an option (1, 2, or 3) to resolve this conflict" << endl;
    cout << endl;
    cout << "1) convince them you are the manager, and hold superiority (charisma)" << endl;
    cout << "2)Use your legal prowess to prove that you are in the right (intelligence)" << endl;
    cout << "3) Stand strong against her yelling (constitution)" << endl;

    cin >> decisionNumber;
    while ((decisionNumber != 1)&&(decisionNumber != 2)&&(decisionNumber != 3)) {
      cout << "Please enter 1, 2, or 3" << endl;
      cin >> decisionNumber;
    }

    if (decisionNumber == 1) {
      diceResult = diceResult + charisma;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: As she finishes her rant about the unfairness of customer treatment and the malpractice of business in relation to jean colors, she demands to speak to your manager." << endl;
        cout << "" << endl;
        cout << "You hold up your hand, with power and boldness, acting as the last defense against American hypocrisy." << endl;
        cout << "" << endl;
        cout << "I am the manager." << endl;
        cout << "" << endl;
        cout << "Your voice echos for miles upon miles. While an initial lie, the presence you hold convinces her, leaving her writhing at the core. The last thing you hear of her before she dissipates into the floor below is 'I'M MELTING! I'M MEEEEEEELLLTIINNGGG..." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You try to convince her that you are the manager, but unfortunately the real manager comes out at the exact same moment. She sees right through the attempted lie and, appalled at your audacity to even claim such power, screams in rage." << endl;
        cout << "" << endl;
        cout << "Everything goes dark for a second, and when the darkness dissipates, you see everything in the store tossed around like a tornado came in. The karen is gone, but you spend an unnecessarily long time cleaning the mess up." << endl;
        cout << "" << endl;
        
      }
    }
    else if (decisionNumber == 2) {
      diceResult = diceResult + intelligence;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: You clearly assert that the customer is wrong in this case, that the store is selling the right color of jeans, and that the dark blue color is in the defined spectrum of 'blue', not counting as mislabeling. Just as she starts to make a rebuttal, you take out a copy of the legal manual instated by the Target company, and instinctually flip to the exact line that declares it. She tries to say something but just starts stuttering, and runs out." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You try to tell her that dark blue is legally a label of blue, but start stuttering as you fall to the ground unconscious. Now you have an official lawsuit against the local branch for 'jeans not being blue'." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 3) {
      diceResult = diceResult + constitution;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: The shouting and screaming commences, making eardrums blow out of nearby customers and glass to start shattering. But you keep your cool, thinking about your day, wondering what's for lunch, and if Cyberpunk 2077 will ever release..." << endl;
        cout << "" << endl;
        cout << "By the time you come back to reality, the Karen just stands there in disbelief at your constitutional strength, and retreats out of the store when she is caught by a guard for vandalism (breaking the glass windows with her yells)." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You try to stand up to the bully karen, but her voice booms harder and louder than any person on earth. Your body can't handle it as you watch yourself quake and crumble to the ground. The karen simply walks over your ragdoll body, looking for its next prey..." << endl;
        cout << "" << endl;
      }
    }

    

  }
  else if (taskInt == 6) {
    //clean bathrooms
    ++untilLunchBreak;
    cout << "Clean Bathrooms:" << endl;
    cout << endl;
    cout << "During your time cleaning out the bathrooms and withstanding the noxious gas, you earned +2 constitution!" << endl;
    constitution += 2;
    cout << "Constition points: " << constitution << endl;
    cout << endl;
    cout << "Decision Event: A pack of sewer rats and their giant rat king start to emerge from the toilet!" << endl;  
    diceResult = dieRoll(diceResult);
    cout << "Choose an option (1, 2, or 3) to resolve this conflict" << endl;
    cout << endl;
    cout << "1) Use rat poison on the toilet rats (intelligence test)" << endl;
    cout << "2) Convince the king of the rats to buy at Target (charisma test)" << endl;
    cout << "3) Try to plunge them back to the abyss (strength test)" << endl;
    
  cin >> decisionNumber;
    while ((decisionNumber != 1)&&(decisionNumber != 2)&&(decisionNumber != 3)) {
      cout << "Please enter 1, 2, or 3" << endl;
      cin >> decisionNumber;
      
    }
    
    if (decisionNumber == 1) {
      diceResult = diceResult + intelligence;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: With your knowledge of the proper application of pest determent, you set touch-based traps within the toilets and watch as the rats climbing out fall back in." << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You have poisoned the toilet. What the actual hell. A customer eventually comes out screaming bloody murder because some backlog toilet water got on his behind and hes now irritatedly itching his pants." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 2) {
      diceResult = diceResult + charisma;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: You summon the King of the rats from the toilet using toilet paper as fine parchment. You successfully convey a peace treaty and an economic endeavor that has the rats using Target as their exclusive trade partner!" << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You summon the King of the rats from the toilet using toilet paper as fine parchment. However, your difficult attitude geared towards cleaning the bathroom is conveyed to the King as a declaration of war. Now Target has to hire pest control and pull a Robespiere for the rat kingdom." << endl;
        cout << "" << endl;
      }
    }
    else if (decisionNumber == 3) {
      diceResult = diceResult + strength;
      cout << "You got a " <<  diceResult << endl;
      if (diceResult > 5){
        successNumber = successNumber + 1;
        cout << "SUCCESS: With the strength of Zeus himself you fight against horde after horde of rats, and none get past the rubber curtain of your mighty plunger!" << endl;
        cout << "" << endl;
      }
      else if (diceResult <= 5) {
        cout << "FAILURE: You put down the plunger into the toilet, but the rats just chew through the rubber. Actually, they just chew right through the porcelain of the toilet, and even through the linoleum floors. Are you sure these are rats?" << endl;
        cout << "" << endl;
      }
    }

    
  }

  cout << "Type 'Next' to continue: " << endl;
  cin >> userInput; 
  
  userInput = whileNotNext(userInput); //This will ask to text next.
  userInput = userNext(userInput); //this will return as 'Next'
  cout << endl;

  //don't touch this curly bracket pls
  }
  
  if (successNumber >= 3)
  {
    cout << "CONGRATS!!!" << endl;
    cout << endl;
    cout << "YOU ARE NOT FIRED!" << endl;
    cout << "Type 'Next' to continue: " << endl;
    cin >> userInput; 
  
    userInput = whileNotNext(userInput); //This will ask to text next.
    userInput = userNext(userInput); //this will return as 'Next'
    cout << endl;
    cout << "So you have made it. At least half or more of the trials and tribulations of the American workforce have been overcome by you. Now what?" << endl;
    cout << endl;
    cout << "You do it over... and over... and over a billion times over again." << endl;
    cout << "Type 'Next' to continue: " << endl;
    cin >> userInput; 
  
    userInput = whileNotNext(userInput); //This will ask to text next.
    userInput = userNext(userInput); //this will return as 'Next'
    cout << endl;
    cout << "Humanity is inherently flawed. We makes mistakes, and we cause turmoil for those around us. Humanity bleeds for those above and below, but that is what makes places like Target survive. Our society requires the blood, sweat, and tears of the workforce to function. You are a part of that workforce..." << endl;
    cout << "Type 'Next' to continue: " << endl;
    cin >> userInput; 
  
    userInput = whileNotNext(userInput); //This will ask to text next.
    userInput = userNext(userInput); //this will return as 'Next'
    cout << endl;
    cout << "For only one thing truly prospers from this capitalist society, the market. It transactions between consumer and product is the only mechanism that allows this world to continue to spin..." << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Welcome to Target..." << endl;
    cout << "(GOOD ENDING)" << endl;

  }

  else
  {
    cout << "YOU ARE FIRED!!!" << endl;
    cout << endl;
    cout << "Type 'Next' to continue: " << endl;
    cin >> userInput; 
  
    userInput = whileNotNext(userInput); //This will ask to text next.
    userInput = userNext(userInput); //this will return as 'Next'
    cout << endl;
    cout << "So you have failed. More than half of the obstacles presented bested your efforts. Now what?" << endl;
    cout << endl;
    cout << "You move on... You pick up the pieces... try to find a new job.." << endl;
    cout << "Type 'Next' to continue: " << endl;
    cin >> userInput; 
  
    userInput = whileNotNext(userInput); //This will ask to text next.
    userInput = userNext(userInput); //this will return as 'Next'
    cout << endl;
    cout << "Humanity is inherently flawed. We makes mistakes, and we cause turmoil for those around us. Humanity bleeds for those above and below, but that is what makes places like Target survive. Our society requires the blood, sweat, and tears of the workforce to function. You are a part of that workforce..." << endl;
    cout << "Type 'Next' to continue: " << endl;
    cin >> userInput; 
  
    userInput = whileNotNext(userInput); //This will ask to text next.
    userInput = userNext(userInput); //this will return as 'Next'
    cout << endl;
    cout << "For only one thing truly prospers from this capitalist society, the market. It transactions between consumer and product is the only mechanism that allows this world to continue to spin..." << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Goodbye Target..." << endl;
    cout << "(BAD ENDING)" << endl;
  }
  cout << "Developed by: " << endl;
  cout << "Alex Camilleri" << endl;
  cout << "Huud Ahmad" << endl;  
  cout << "Ben Bravo" << endl;  
  cout << "Chantal Arguelles" << endl;
  return 0;
}
