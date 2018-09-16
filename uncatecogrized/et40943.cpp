#include <iostream>
#include <string>
using namespace std;

class Data{
	private:
		int ZIPcode;
		string name,address,city,state;
	public:
		Data(){};
		Data(string _name,string _address,string _city,string _state,int _ZIPcode):
			name(_name),address(_address),city(_city),state(_state),ZIPcode(_ZIPcode){}
		string getname()const{
			return name;
		}
	friend istream& operator>>(istream& in,Data &n);
};
istream& operator>>(istream& in,Data &n){
	in>>n.name>>ws;
	getline(in,n.address);
	in>>n.city>>n.state>>n.ZIPcode;
	return in;
}
class Package{
private:
	int weight;
	Data sender,recipient;
public:
	Package(int _weight,Data _sender,Data _recipient):
	weight(_weight),sender(_sender),recipient(_recipient){}
	string get_sender_name()const{
		return sender.getname();
	}
	string get_recipient_name()const{
		return recipient.getname();
	}
	int getWeight()const{
		return weight;
	}
	virtual int calculateCost()const{
		return 2*weight;
	}
};

class TwoDayPackage: public Package{
public:
	TwoDayPackage(int _weight,Data _sender,Data _recipient):
		Package(_weight,_sender,_recipient){}
	virtual int calculateCost()const{
		return Package::calculateCost()+20;
	}
};

class OvernightPackage : public Package{
public:
	OvernightPackage(int _weight,Data _sender,Data _recipient):
		Package(_weight,_sender,_recipient){}
	virtual int calculateCost()const{
		return Package::calculateCost()+5*Package::getWeight();
	}
};

int main(int argc, char const *argv[])
{
	int t,weight;
	string package_type;
	Data sender,recipient;
	cin>>t;
	for(int i=0;i<t;i++){
		if(i)cout<<'\n';
		cin>>package_type>>weight>>sender>>recipient;
		if(package_type=="TwoDay"){
			TwoDayPackage p=TwoDayPackage(weight,sender,recipient);
			cout<<p.get_sender_name()<<' '<<p.get_recipient_name()<<' '<<p.calculateCost()<<'\n';
		}else{
			OvernightPackage p=OvernightPackage(weight,sender,recipient);
			cout<<p.get_sender_name()<<' '<<p.get_recipient_name()<<' '<<p.calculateCost()<<'\n';
		}
	}
	return 0;
}
