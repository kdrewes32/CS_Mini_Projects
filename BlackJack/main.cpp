/**
 Write a function named noNegatives(). It should accept an array of integers and a size argument. It should return true if none of the values are negative. If any of the values are negative it should return false
         bool noNegatives(const int array[], int size);
 Write a function named absoluteValues(). It should accept an array of integers and a size argument. It should replace any negative values with the corresponding positive value.
         void absoluteValues(int array[], int size);
 Write a function named eCount. It should accept an array of chars and a size argument. It should return the number of times that the character 'e' shows up in the array.
         int eCount(const char array[], int size);
 Write a function named charCount. It should be similar to eCount, but instead of counting 'e's it should accept a third argument, a target char. The function should return the number of times the target char shows up in the array.
         int charCount(const char array[], int size, char targetChar);
 Write a function named isSorted. It should accept an array of integers and a size argument. It should return true if the values are sorted in ascending order. False if they are not.
         bool isSorted(const int array[], int size);
 Write a function named equalNeighbors. It should accept an array of chars and a size argument. It should return true if there are two adjacent elements in the array with equal values. If there are not, it should return false.
         bool equalNeighbors(const char array[], int size);
 This is not a homework Lab, so feel free to post your code to one of these (not more than one) to the forum at any time.
 For Credit
 
 Lab 4.1 [45 points]
 Write a program that reads HAND_SIZE cards from the user, then analyzes the cards and prints out the type of poker hand that they represent. (HAND_SIZE will be a global constant, typically 5, but your program must still work if it is set to something other than 5.)
 Poker hands are categorized according to the following hand-types: Straight flush, four of a kind, full house, straight, flush, three of a kind, two pairs, pair, high card.
 To simplify the program we will ignore card suits, and face cards. The values that the user inputs will be integer values from LOWEST_NUM to HIGHEST_NUM. (These will be global constants. We'll use LOWEST_NUM = 2 and HIGHEST_NUM = 9, but your program must work if these are set to something different.) When your program runs it should start by collecting HAND_SIZE integer values from the user and placing the integers into an array that has HAND_SIZE elements. It might look like this:
 
 Enter 5 numeric cards, no face cards. Use 1- 9.
 Card 1: 8
 Card 2: 7
 Card 3: 8
 Card 4: 2
 Card 5: 3
 
 (This is a pair, since there are two eights)
 No input validation is required for this assignment. You can assume that the user will always enter valid data (numbers between LOWEST_NUM and HIGHEST_NUM).
 Since we are ignoring card suits there won't be any flushes. Your program should be able to recognize the following hand categories, listed from least valuable to most valuable:
 
 Hand Type                                      Description                                                                                      Example
 High Card                                      There are no matching cards, and the hand is not a straight                                      2, 5, 3, 8, 7
 Pair                                           Two of the cards are identical                                                                   2, 5, 3, 5, 7
 Two Pair                                       Two different pairs                                                                              2, 5, 3, 5, 3
 Three of a kind                                Three matching cards                                                                             5, 5, 3, 5, 7
 Straight                                       5 consecutive cards                                                                              3, 5, 6, 4, 7
 Full House                                     A pair and three of a kind                                                                       5, 7, 5, 7, 7
 Four of a kind                                 Four or more matching cards                                                                      2, 5, 5, 5, 5
 
 A note on straights: a hand is a straight regardless of the order. So the values 3, 4, 5, 6, 7 represent a straight, but so do the values 7, 4, 5, 6, 3. Also, a straight requires just 5 consecutive cards, even if HAND_SIZE is larger than 5.
 Your program should read in HAND_SIZE values and then print out the appropriate hand-type. If a hand matches more than one description, the program should print out the most valuable hand type.
 Here are three sample runs of the program:
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 8
 Card 4: 2
 Card 5: 7
 Two Pair!
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 4
 Card 4: 6
 Card 5: 5
 Straight!
 Enter 5 numeric cards, no face cards. Use 2 - 9.
 Card 1: 9
 Card 2: 2
 Card 3: 3
 Card 4: 4
 Card 5: 5
 High Card!
 
 Additional Requirements
 1) You must write a function for each hand type. Each function must accept a const int array that contains HAND_SIZE integers, each representing one of the HAND_SIZE cards in the hand, and must return "true" if the hand contains the cards indicated by the name of the function, "false" if it does not. The functions must have the following prototypes.
 bool  containsPair(const int hand[]);
 bool  containsTwoPair(const int hand[]);
 bool  containsThreeOfaKind(const int hand[]);
 bool  containsStraight(const int hand[]);
 bool  containsFullHouse(const int hand[]);
 bool  containsFourOfaKind(const int hand[]);
 Important! In the descriptions below, a pair is defined as exactly two of the same card. If there are more than two of the same card, that is not a pair. Similarly, a three-of-a-kind is defined as exactly three of the same card. If there are more than three of the same card, that is not a three-of-a-kind. However! Since there is no such hand as five-of-a-kind or more, four-of-a-kind must return true if there are four or more of the same card.
 // post:  returns true if and only if there are one or more pairs in the hand.  Note that
 // this function returns false if there are more than two of the same card (and no other pairs).
 bool  containsPair(const int hand[]);
 // post: returns true if and only if there are two or more pairs in the hand.
 bool  containsTwoPair(const int hand[]);
 // post: returns true if and only if there are one or more three-of-a-kind's in the hand.
 bool  containsThreeOfaKind(const int hand[]);
 // post: returns true if there are 5 consecutive cards in the hand.
 bool  containsStraight(const int hand[]);
 // post: returns true if there is are one or more pairs and one or more three-of-a-kind's in the hand.
 bool  containsFullHouse(const int hand[]);
 // post: returns true if there are one or more four-of-a-kind's in the hand.
 bool  containsFourOfaKind(const int hand[]);
 Some examples:
 A hand that contains three-of-a-kind and two other different cards (for example, 1, 1, 1, 2, 3) should return "false" for "containsPair()"
 A hand that contains four-of-a-kind should return "false" for "containsPair()" and "containsThreeOfaKind()"
 A hand that contains a full-house should return "true" for containsThreeOfaKind() and containsPair().
 A hand that contains two-pair should return "true" for containsPair().
 Here is a table with some examples that I hope will help clear up any confusion. If there are additional hands that you are unsure about, please ask in the discussion, and I will consider adding rows to this table for further clarification.
 
 hand                  pair?               two-pair?          three-of-a-kind?            full-house?            four-of-a-kind?             straight?
 2, 2, 2, 3, 4         F                   F                  T                           F                      F                           F
 2, 3, 3, 3, 3         F                   F                  F                           F                      T                           F
 2, 2, 3, 3, 3         T                   F                  T                           T                      F                           F
 2, 2, 3, 3, 4         T                   T                  F                           F                      F                           F
 2, 2, 2, 3, 3, 3      F                   F                  T                           F                      F                           F
 9, 2, 4, 3, 6, 5      F                   F                  F                           F                      F                           T
 4, 2, 6, 8, 7, 5      F                   F                  F                           F                      F                           T 
 
 
 I would suggest that before you submit your program you test it using each of the above examples.
 2) You do not need to write a containsHighCard function. All hands contain a highest card. If you determine that a particular hand is not one of the better hand types, then you know that it is a High Card hand.
 3) Do not sort the cards in the hand. Also, do not make a copy of the hand and then sort that.
 4) An important objective of this assignment is to have you practice creating excellent decomposition. Don't worry about efficiency on this assignment. Focus on excellent decomposition, which results in readable code. This is one of those programs where you can rush and get it done but end up with code that is really difficult to read, debug, modify, and re-use. If you think about it hard, you can think of really helpful ways in which to combine the tasks that the various functions are performing. 5 extra credit points on this assignment will be awarded based on the following criteria: no function may have nested loops in it. If you need nested loops, the inner loop must be turned into a separate function, hopefully in a way that makes sense and so that the separate function is general enough to be re-used by the other functions. Also, no function other than main() may have more than 5 lines of code. (This is counting declarations, but not counting the function header, blank lines, or lines that have only a curly brace on them.) In my solution I was able to create just 3 helper functions, 2 of which are used repeatedly by the various functions.
 These additional criteria are intended as an extra challenge and may be difficult for many of you. If you can't figure it out, give it your best shot, but don't be too discouraged. It's just 5 points. And be sure to study the posted solution carefully.
 Suggestions
 
 1) I strongly suggest that you never compare cards with each other. This is often the instinctive direction that students go at first. For example, to find whether the hand contains a pair, you may be tempted to compare every card in the hand with every other card in the hand. I suggest that instead, you count how many of each card there are.
 2) If you find that you are really struggling with even the containsPair() function, I suggest that you solve an even simpler problem first: write a function that returns true if the hand contains a pair of 2's (false otherwise). Just count how many 2's there are in the hand, and return true if there are two or more of them (false otherwise).
 3) Test these functions independently. Once you are sure that they all work, the program logic for the complete program will be fairly straightforward.
 Here is code that tests a containsPair function:
 int main() {
         int hand[] = {2, 5, 3, 2, 9};
         if (containsPair(hand)) {
                 cout << "contains a pair" << endl;
         }
 }
 */
#include <iostream>

//----------------------------------------------------------------------

bool containsPair(const int []);

bool containsTwoPair(const int []);

bool containsThreeOfaKind(const int []);

bool containsStraight(const int []);

bool containsStraightHelper(const int []);

bool containsFullHouse(const int []);

bool containsFourOfaKind(const int []);

bool IsDifferent(const int []);

bool IsDifferentHelper(const int [],int,bool&,int&);

bool NoPairs(const int []);

bool NoPairsHelper(const int [],int);

int Counter(const int []);

void CounterHelper(const int [], int, int&);

int Lowest(const int [],int);

int Highest(const int [],int);

void Input(int []);

void Result(int [],size_t);

//----------------------------------------------------------------------
const int HAND_SIZE = 5;
int main()
{
    int hand[HAND_SIZE];
    
    Input(hand);
    
    Result(hand,sizeof(hand)/sizeof(hand[0]));
   
    std::cout << std::endl;
    
    return 0;
}
//----------------------------------------------------------------------

bool containsPair(const int hand[])
{
    if(Counter(hand)==1)
    return true; return false;
}
//----------------------------------------------------------------------

bool containsTwoPair(const int hand[])
{
    if(Counter(hand)==2 && IsDifferent(hand))
    return true; return false;
}

//----------------------------------------------------------------------

bool  containsThreeOfaKind(const int hand[])
{
    if(Counter(hand)==3 && !IsDifferent(hand))
    return true; return false;
}
//----------------------------------------------------------------------

bool  containsStraight(const int hand[])
{
    if(NoPairs(hand))
        if(containsStraightHelper(hand)) return true;
    return false;
}
//----------------------------------------------------------------------

bool containsStraightHelper(const int hand[])
{
    bool confirmation = false;
    int low = Lowest(hand,HAND_SIZE);
    int temp = 0;
  
    for(int i = 0; i < HAND_SIZE; i++)
    {
        for(int j = 0; j < HAND_SIZE; j++)
        {
            if(hand[j]-low == 1)
            {
                confirmation = true;
                temp = hand[j];
            }
        }
        
        if(confirmation)
        low = temp;
        
        if(!confirmation && i != 4)
            return false;
        
            confirmation = false;
        
    }       return true;
}
//----------------------------------------------------------------------

bool  containsFullHouse(const int hand[])
{
    if(Counter(hand)==4 && IsDifferent(hand))
        return true; return false;
}
//----------------------------------------------------------------------

bool  containsFourOfaKind(const int hand[])
{
    if(Counter(hand)==6 && !IsDifferent(hand))
    return true; return false;
}
//----------------------------------------------------------------------

bool IsDifferent(const int hand[])
{
    bool flag = true; int temp = 0;
    for(int i = 0; i < HAND_SIZE; i++)
    if(IsDifferentHelper(hand,i,flag,temp)) return true;

    return false;
}
//----------------------------------------------------------------------

bool IsDifferentHelper(const int hand[], int i, bool &flag, int &temp)
{
    for(int j = 0; j < HAND_SIZE; j++)
    {
        if((hand[i]==hand[j]) && i!=j)
        {
            if(flag)
            {
                temp = hand[j];
                flag = false;
            }
            else if(temp!=hand[j])
                return false;
        }
    }           return true;
}
//----------------------------------------------------------------------

bool NoPairs(const int hand[])
{
    for(int i = 0; i < HAND_SIZE; i++)
    if(!NoPairsHelper(hand,i))return false;
    return true;
}
//----------------------------------------------------------------------

bool NoPairsHelper(const int hand[],int i)
{
    for(int j = 0; j < HAND_SIZE; j++)
    {
        if((hand[i]==hand[j]) && i!=j )
            return false;
    }       return true;
}
//----------------------------------------------------------------------

int Counter(const int hand[])
{
    int counter = 0;
    
    for(int i = 0; i < HAND_SIZE; i++)
        CounterHelper(hand,i,counter);
    
        return counter;
}
//----------------------------------------------------------------------

void CounterHelper(const int hand[],int i,int &counter)
{
    for(int j = i+1; j < HAND_SIZE; j++)
        if((hand[i]==hand[j]) && i!=j )
            counter++;
}
//----------------------------------------------------------------------

int Highest(const int array [],int size)
{
    int i = 0,
        highest = INT_MIN;
    
    for(i = 0; i < size; i++)
        if(array[i] > highest)
            highest = array[i];
    
    return highest;
}
//----------------------------------------------------------------------

int Lowest(const int array [],int size)
{
    int i = 0, low = INT_MAX;
    
    for(i = 0; i < size; i++)
        if(array[i] < low)
            low = array[i];
    
    return low;
}
//----------------------------------------------------------------------

void Input(int hand [])
{
    std::cout << "Enter 5 numeric cards, no face cards. Use 1 - 9." << std::endl;
    
    for(int i = 0; i < HAND_SIZE;i++)
    {
        std::cout << "\nCard " << i+1 << ": ";
        std::cin >> hand[i];
        
        if(!std::cin || (hand[i] < 1) || (hand[i] > 9))
        {
            std::cout << "\nInvalid Entry, please re-enter\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            --i;
        }
    }
}
//----------------------------------------------------------------------

void Result(int hand [],size_t size)
{
    if(NoPairs(hand) && !containsStraight(hand))
        std::cout << "\nHighest card is " << Highest(hand,size);
    else
    {
    if(containsPair(hand))
        std:: cout << "\ncontains a pair" << std::endl;
    
    else if (containsTwoPair(hand))
        std::cout << "\ncontains a two pair" << std::endl;
    
    else if (containsThreeOfaKind(hand))
        std::cout << "\ncontains a three of a kind" << std::endl;

    else if (containsStraight(hand))
        std::cout << "\ncontains a straight" << std::endl;

    else if (containsFullHouse(hand))
        std::cout << "\ncontains a full house" << std::endl;

    else if (containsFourOfaKind(hand))
        std::cout << "\ncontains a four of a kind" << std::endl;
    }
}
//----------------------------------------------------------------------
