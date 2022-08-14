###############################################################
ReadMe for assignment submitted by 2019B4PS0671P
###############################################################
###############################################################
Description of how to run the code and observe the output:
1. The exe file is called KBC.exe. It is a quiz/game based application based on Kaun Banega Crorepati game.
2. The input file is KBC QUESTION BANK.txt. It has 120 questions along with their options and answers. 
    For every game questions are randomly picked from the file and displayed on the screen.
3. When you run the exe, you will have to play the game atleast once. You can play the game multiple times as well.
4. In any round not more than 15 questions will be displayed. In every round you will have two lifelines 50-50 and Flip the question which can be used ONCE each.
    Implementation of 50-50 lifeline will delete two incorrect options from screen and flip the question will change the question.
5. Before starting of each round the rules of the game will be displayed and the game will not proceed further until any character has been entered by the user.
6. Once you start playing the game, your score and available lifelines(50-50 and flip the question) along with their status will be shown on top.
7. First 5 questions are time based questions and 45 seconds are allotted to answer a question. 
    Answers entered after 45 seconds will be accepted but not evaluated and the game will end. To compensate for time consumed in implementing 50-50 lifeline the time 
    limit will be extended by 5 seconds. This is not applicable to flip the question.
8. To use fifty-fifty lifeline you can press 1 and to use flip the question lifeline you can press 2. To answer you only have to enter the option number(A,B.C,D) in any case.
    At any time you can quit the game by typing QUIT as your answer.
9. After every round the user will be asked whether he wants to continue playing or end the game. To end the game enter END/end and to continue you can enter any other 
    letter/word.
###############################################################
Known limitations of the code:
1. Due to restrictions on using thrid party tools the countdown time(every second) cannot be displayed on the screen.
###############################################################
Contributions of the team members:
Snehal did modules 1 and 2 and timer.
Anika did modules 3 and 4.
Ramkrishna did modules 5 and 6.
Screen aesthetics and other related work was done equally by all the members.
###############################################################
