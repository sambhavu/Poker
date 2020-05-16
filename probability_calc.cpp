#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstdlib> 
using namespace std;

vector<string> testv =
{
	"qc",
	"jc",
	"ac",
	"3d",
	"kc",
	"tc",
};

vector<string> straight = 

{
	"a",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"t",
	"j",
	"q",
	"k",
	"a",
	"2",
	"3",
	"4",
	"5",
}; 
	


class poker	
{
	public: 
	
	int CashinAmount;
	int money;
	int pot;
	
	
	std::vector<string> deck;
	std::vector<int> dealt_cards;
	std::vector<string> hand; 
	std::vector<string> table;
	std::vector<char> tstraight;
	
	poker();
	void play(); 
	
	void reset_deck();
	string deal_card(); 
	void get_hand();
	void show_hand();
	
	void bet();
	
	void preflop_equity(); 
	void show_equity(); 
	void calc_equity(vector<string> match);
	void calcprob(vector<string> calcthis); 
	
	void show_flop(); 
	void show_next(); 
	
	bool toak_(vector<string> match); 
	bool twopair_(vector<string> match);
	bool pair_(vector<string> match); 
	bool flush_(vector<string> match); 
	bool straight_(vector<string> match); 
	bool fh_(vector<string> match); 
	int get_straight_p(char s); 
	bool sf_(vector<string> match);
	bool foak_(vector<string> match); 
	bool rf_(vector<string> match); 
	
	int tsize; 
	
	double testsize; 
	double rfc, rfp; 
	double sfc, sfp;
	double foakc, foakp; 
	double fhc, fhp;
	double flushc, flushp;
	double straightc, straightp; 
	double toakc, toakp; 
	double tpc, tpp;
	double pp, pc; 
	
	void resetprob(); 
	
	
};

bool poker:: rf_(vector<string> match) 
{
	bool rf=false;
	bool flush = flush_(match); 
	bool str8 = straight_(match);
	
	int sz=tstraight.size();
	

	
	
	int count; 
	
	if(flush && str8)
	{
		for(int i=0; i<sz; i++) 
		{ 
			if(tstraight[i] == 't')
			{
				count++; 
			} 
			if(tstraight[i] == 'j')
			{
				count++; 
			} 
			if(tstraight[i] == 'q')
			{
				count++; 
			} 
			if(tstraight[i] == 'k')
			{
				count++; 
			}
			if(tstraight[i] == 'a')
			{
				count++; 
			} 
			
			//cout<<tstraight[i]<<"\n";
		} 
		
	}
	
	if(count==5) 
	{
		rf=true;
	}
	
	return rf; 
	
}

bool poker:: sf_(vector<string> match) 
{
	bool s , f;
	s=straight_(match); 
	f=flush_(match); 
	
	if( s && f )
	 {
	 	return true; 
	 }
	 else 
	 {
	 	return false;
	 }
}
	
bool poker::foak_(vector<string> match) 
{
	int si; 
	si=match.size();
	
	bool foak=false; 
	
	char num, type, numt, typet;
	string test, testt; 
	
	int pair;
	
	for(int k=0; k<si;k++)
	{
		pair=0; 
		
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt)
		    {
		    	pair++; 
		    } 
		    
		    
		    if(pair==3 && num==numt){
		    	foak=true;
		    	goto found; 
		    }
		    
		    
		} 
	
	}
	
	found:
	return foak;
	
	
}


bool poker::fh_(vector<string> match) 
{
	bool fh = false; 
	if(toak_(match))
	 {
	 	int si; 
	    si=match.size();
	
	char num, type, numt, typet,tp;
	string test, testt; 
	
	int pair;
	
	for(int k=0; k<si;k++)
	{
		pair=0; 
		
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt)
		    {
		    	pair++; 
		    } 
		    
		    
		    if(pair==2 && num==numt){
		    	tp=num;
		    	goto found; 
		    }
		    
		    
		} 
	
	
	    
	 } 
	 
	 found: 
	 
	 for(int k=0; k<si;k++)
	{
		// J 9 3 5 6 6
			
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt && num!=tp)
		    {
		    	fh=true;
		    	goto found2;
		    } 
		    
		    
		} 
	
	}
	 
	 
	 
	 
  }
  
  found2:
  
  return fh;
} 

	
	 	

bool poker::flush_(vector<string> match) 
{
	int si; 
	si=match.size();
	
	bool flush=false; 
	
	char num, type, numt, typet;
	string test, testt; 
	
	int pair;
	
	for(int k=0; k<si-1;k++)
	{
		pair=0; 
		
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(type==typet)
		    {
		    	pair++; 
		    } 
		    
		    
		    if(pair==4 && type==typet){
		    	flush=true;
		    	goto found; 
		    }
		    
		    
		} 
	
	}
	
	found:
	return flush;
	
} 

bool poker::straight_(vector<string> match) 
{
	
	int si; 
	si=match.size();
	
	bool bstraight=false; 
	
	char num, type, numt, typet;
	string test, testt, temp;
	
	int pair;
	int sp;
	
	char s1, s2, s3, s4; 
	
	for(int k=0; k<si; k++)
	{	
		
		pair=1; 
		tstraight.clear();
		
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
	    sp = get_straight_p(num);
			
		temp=straight[sp+1]; 
		s1 = temp.at(0); 
			
		temp=straight[sp+2]; 
		s2=temp.at(0); 
			
		temp=straight[sp+3];
		s3=temp.at(0); 
			
		temp=straight[sp+4]; 
		s4=temp.at(0); 
			
		//cout<<"straight: "<<num<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<"\n";
		
		tstraight.push_back(num); 
		
		for(int l=0; l<si; l++) 
		{ 
			
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			int nsize; 
			nsize=tstraight.size(); 
			
			for(int i=0; i<nsize; i++) 
			{
				
				if(numt==tstraight[i])
				{
					goto skp;
				} 
			}
			
		
			if(numt==s1) 
			{
				pair++; 
				tstraight.push_back(s1);
				
			} 
			if(numt==s2) 
			{
				pair++; 
				tstraight.push_back(s2);
			} 
			if(numt==s3)
			{
				pair++; 
				tstraight.push_back(s3); 
			} 
			if(numt==s4)
			{
				pair++;
				tstraight.push_back(s4);
			} 
			
			skp:
			
			if(pair==5)
			{
				bstraight = true;
				goto found;
			
			}
			
			
			
	       }
   }
   
   found:
   return bstraight;
   
 } 
   

int poker:: get_straight_p(char s)
{
	int i;
	int siz= straight.size();
	string temps;
	char temp; 
	
	for(i=0; i<siz; i++)
	{
		temps=straight[i]; 
		
		temp = temps.at(0); 
		
		if(s==temp)
		{
			
			return i; 
		} 
	}
	
	
}
	   

bool poker::toak_(vector<string> match) 
{
	int si; 
	si=match.size();
	
	bool toak=false; 
	
	char num, type, numt, typet;
	string test, testt; 
	
	int pair;
	
	for(int k=0; k<si;k++)
	{
		pair=0; 
		
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt)
		    {
		    	pair++; 
		    } 
		    
		    
		    if(pair==2 && num==numt){
		    	toak=true;
		    	goto found; 
		    }
		    
		    
		} 
	
	}
	
	found:
	return toak;
	
} 

bool poker::twopair_(vector<string> match) 
{
	int si; 
	si=match.size();
	
	bool twopair=false; 
	
	char num, type, numt, typet;
	string test, testt; 
	
	int thatsapair; 
	
	for(int k=0; k<si;k++)
	{
		// J 3 3 5 6 6
			
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt)
		    {
		    	thatsapair++; 
		    } 
		    
		    
		    if(thatsapair==2){
		    	twopair=true;
		    	goto found; 
		    }
		    
		    
		} 
	
	}
	
	found:
	return twopair;
} 

bool poker::pair_(vector<string> match) 
{
	int si; 
	si=match.size();
	
	bool pair=false; 
	
	
	char num, type, numt, typet;
	string test, testt; 
	
	
	for(int k=0; k<si;k++)
	{
		// J 9 3 5 6 6
			
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt)
		    {
		    	pair=true;
		    	goto found;
		    } 
		    
		    
		} 
	
	}
	
	found:
	return pair;
} 

void poker::show_equity()
{
	//combine hand and table 
	vector<string> match;
	
	int hsi, tsi;
	
	hsi=hand.size();
	tsi=table.size(); 
	
	for(int i=0; i<hsi; i++) 
	{
		match.push_back(hand[i]); 
	} 
	
	for(int j=0; j<tsi; j++)
	{
		match.push_back(table[j]);
	}
	
	int msize; 
	msize=match.size(); 
	
	//find # matches within match<> 
	calc_equity(match); 
	
	//match=testv; 

if(msize==7)
{
	
	if(rf_(match))
	{
		cout<<"Royal Flush";
	}
	
	else if(sf_(match))
	{
		cout<<"Straight Flush"; 
	}
	
	else if(foak_(match))
	{
		cout<<"Four of A Kind";
	}
	
	else if(fh_(match)) 
	{
		cout<<"Full House";
	}
	
	else if(flush_(match))
	{
		cout<<"Flush"; 
	}
	
	else if(straight_(match))
	{
		cout<<"Straight";
	}
	
	else if(toak_(match))
	{
		cout<<"Three of a kind";
	}
	else if(twopair_(match))
	{
		cout<<"Two Pair"; 
	}
	else if(pair_(match))
	{
		cout<<"One pair";
	} 
	else { 
		cout<<"High Card";
	} 
}

else{
	cout<<"\nProbabilities: \n"; 
	cout<<"Royal Flush     ->"<<rfp*100<<"%\n";
	cout<<"Straight Flush  ->"<<sfp*100<<"%\n";
	cout<<"Four of a Kind  ->"<<foakp*100<<"%\n";
	cout<<"Full House      ->"<<fhp*100<<"%\n";
	cout<<"Flush           ->"<<flushp*100<<"%\n"; 
	cout<<"Straight        ->"<<straightp*100<<"%\n";
	cout<<"Three of a Kind ->"<<toakp*100<<"%\n"; 
	cout<<"Two Pair        ->"<<tpp*100<<"%\n";
	cout<<"One Pair        ->"<<pp*100<<"%\n"; 
	
	
}

	
	cout<<"\n\n"; 
	
}

void poker:: preflop_equity()
{
	
}




void poker::show_flop()
{ 
	string b1; 
	
	string c1, c2, c3;
	
	b1= deal_card(); 
	
	c1=deal_card(); 
	c2=deal_card(); 
	c3=deal_card(); 
	
	table.push_back(c1);
	table.push_back(c2);
	table.push_back(c3); 
	
	int si;
	si=table.size(); 
	
	cout<<"\n[ ";
	
	for(int i=0; i<si; i++)
	     cout<<table[i]<<" "; 
	
	cout<<"]\n\n"; 
	
} 

void poker::show_next()
{
	string b1; 
	
	string c1; 
	
	b1=deal_card(); 
	c1=deal_card(); 
	
	table.push_back(c1); 
	
	int si;
	si=table.size(); 
	
	cout<<"[ "; 
	
	for(int i=0; i<si; i++)
	     cout<<table[i]<<" "; 
	
	cout<<"]\n\n"; 
	
	
	
} 


void poker::bet()
{
	int amount;
	cout<<"Enter Bet Amount \n:";
	cin>> amount; 
	int enoughmoney=1;
	
	while(enoughmoney)
	{ 
		if(amount>money)
		{
		cout<<"Not Enough Money\nEnter Bet Amount \n:";
			cin>>amount; 
		 }
		 else{
		 	enoughmoney=0;
		 }
	 } 
	 
	 money=money-amount;
	 pot=pot+amount;
	
}

void poker::show_hand()
{
	cout<<"\nH[";
	cout<<hand[0]<<" "<<hand[1]<<"]\n"; 
}

void poker:: play()
{
	string move; 
	
	while(money>0)
	{
		
		
		pot=0; 
		
		//cout<<money<<"\n"; 
		
		reset_deck();
		get_hand();
		show_hand();
		
		//cout<<money<<"\n"; 
		preflop_equity(); 
		
		
		cout<<"\n:";
		cin>>move;
		
		if(move=="n")
		{
			show_flop(); 
			show_equity(); 
			
		} 
		else if(move=="x")	
		{
			break;
		}
		
		else
		{
			cout<<"unclear input-automatic fold\n";
		}
		
		
		cout<<"\n:";
		cin>>move;
		show_hand();
		
		if(move=="n")
		{
			show_next(); 
			show_equity(); 
			
		} 
		else if(move=="x")	
		{
			break;
		}
		
		else
		{
			cout<<"unclear input-automatic fold\n";
		}
		
		
		cout<<"\n:";
		cin>>move;
		show_hand();
		
		if(move=="n")
		{
			show_next(); 
			show_equity(); 
			
		} 
		else if(move=="x")	
		{
			break;
		}
		
		else
		{
			cout<<"unclear input-automatic fold\n";
		}
		
		
		
		
	}
	
	//cout<<"chips: "<<money; 
	
}


void poker::get_hand()
{
	std::string c1;
	std::string c2; 
	
	c1=deal_card();
	c2=deal_card();
	
	hand.push_back(c1);
	hand.push_back(c2); 
	
}
void poker::reset_deck(){
	
	deck.clear();
	hand.clear();
	dealt_cards.clear();
	table.clear(); 
	
	std::vector<string> type;
	std::vector<string> value;
	
	
	type.push_back("d");
	type.push_back("s");
	type.push_back("h");
	type.push_back("c");
	
	std::string v;
	
	for(int i=2; i<=9; i++)
	{
		v=std::to_string(i);
		value.push_back(v);
	}
	
	value.push_back("t");
	value.push_back("j");
	value.push_back("q");
	value.push_back("k");
	value.push_back("a");
	
	std::string card;
	
	int i, j;
	
	i=value.size();
	j=type.size();
	
	for(int k=0; k<i; k++) 
	{
		for(int d=0; d<=3; d++)
		{
			card=value[k]+type[d];
			deck.push_back(card);
		}
		
	}
	
}



poker::poker()
{
	 cout<<"Equity Calculator: n for next \n";
     cout<<"Cash in Chips: ";
     cin>> CashinAmount; 
     money=CashinAmount;
     cout<<"\n\n\n";
     play();
	 
}


string poker::deal_card()
{
	//pick random card from deck 
	//remove card from deck
	//return card 
	int cards;
	int thecard; 
	int dealt;
	
	bool different = 1;
	int check;
	
    std::string card; 
    
    cards=deck.size(); 
	thecard=rand() % cards; 
	
	dealt=dealt_cards.size();
	
	if(dealt==0)
	{
		dealt_cards.push_back(thecard);
		card=deck[thecard]; 
	    return card;
	}
	
	else{
	
	    while(different)
	    {
	    	check = 0; 
	    	
		    for(int i=0; i<dealt; i++)
		    { 
		    	if(thecard==dealt_cards[i])
		    	{
		    		thecard=rand() % cards; 
		    		check=1;
		    		break;
		    	}
		    }
		    
		    if(check==0)
		    {
		    	different=0;
		    }
		    
	    }
	}
	
	
	
    dealt_cards.push_back(thecard);
	card=deck[thecard]; 
	return card;
	
} 


void poker::calc_equity(vector<string> match) 
{
	//create test deck
	
	vector<string> test_deck; 
	vector<string> test_hand; 
	test_hand=match; 
	
	int matchsize= match.size(); 
	int iter=7-matchsize;
	
	
	int decksize=deck.size();
	string temp;
	
	for(int i=0; i<decksize; i++) 
	{
		if(deck[i] != match[i]) 
		{
			temp=deck[i]; 
			test_deck.push_back(temp); 
		}
	} 
	
	tsize=test_deck.size(); 
	
if(iter==1)
{
    resetprob(); 
	testsize=0;
	
	test_hand.push_back("x"); 
	for(int k=0; k<tsize; k++) 
	{
		test_hand[6]=test_deck[k]; 
		calcprob(test_hand); 
		testsize++; 
		
	}
	
}

else if(iter==2)
{   resetprob();
	testsize=0; 
	for(int q=0; q<tsize-1; q++) 
	{
		if(q==0){
			test_hand.push_back(test_deck[q]); 
		}
		else
		{
			test_hand[5]==test_deck[q]; 
		}
		
		for(int u=q+1; u<tsize; u++) 
		{
			if(q==0){
				test_hand.push_back(test_deck[u]); 
			}
			
			else{
				
				test_hand[6]=test_deck[u]; 
			}
			
			calcprob(test_hand); 
			testsize++; 
	    }
    }
  } 
  
  
//preflop probabilites 
  
 else if(iter==5)
{   resetprob();
	testsize=0; 
	for(int q=0; q<tsize; q++) 
	{
		if(q==0){
			test_hand.push_back(test_deck[q]); 
		}
		else
		{
			test_hand[2]==test_deck[q]; 
		}
		
		for(int u=q+1; u<tsize; u++) 
		{
			if(q==0){
				test_hand.push_back(test_deck[u]); 
			}
			
			else{
				
				test_hand[3]=test_deck[u]; 
			}
			
			for(int ii=u+1; ii<tsize; ii++) 
			{
				if(q==0) 
				{
					test_hand.push_back(test_deck[ii]); 
				}
				else{
					test_hand[4]==test_deck[ii];
				}
				
				for(int iq=ii+1; iq<tsize; iq++)
				{
					if(q==0){
				test_hand.push_back(test_deck[iq]); 
					}
					else
					{
						test_hand[5]==test_deck[iq]; 
					}
					
				for(int ip=iq+1; ip<tsize; ip++)
			{
				if(q==0)
				{
					test_hand.push_back(test_deck[ip]); 
				}
				else{ 
					test_hand[6]=test_deck[ip];
			 }
			      calcprob(test_hand); 
			      testsize++; 
				}
				
			} 
	    }
    }
  } 

}
  
  
} 


void poker:: calcprob(vector<string> calcthis) 
{
	
	
	if(rf_(calcthis))
	{
		rfc++;
	}
    if(sf_(calcthis))
	{
		sfc++; 
	}
	if(foak_(calcthis)) 
	{
		foakc++; 
	} 
	if(fh_(calcthis))
	{
		fhc++; 
	}
	if(flush_(calcthis))
	{
		flushc++; 
	}
	if(straight_(calcthis))
	{
		straightc++;
	}
	if(toak_(calcthis))
	{
		toakc++; 
	}
	if(twopair_(calcthis))
	{
		tpc++; 
	}
	if(pair_(calcthis))
	{
		pc++; 
	}
	
	rfp=rfc/testsize;
	sfp=sfc/testsize; 
	foakp=foakc/testsize;
	fhp=fhc/testsize; 
	flushp=flushc/testsize; 
	straightp=straightc/testsize; 
	toakp=toakc/testsize; 
	tpp=tpc/testsize; 
	pp=pc/testsize;
	
}

void poker:: resetprob(){
	
	testsize=0;
	rfc=0; 
	sfc=0;
    foakc=0; 
	fhc=0;
	flushc=0;
	straightc=0; 
	toakc=0; 
	tpc=0; 
	pc=0;
	
} 



int main()
{
	poker player;
	
}
