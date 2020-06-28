#include"orderFile.h"

OrderFile::OrderFile()//
{
	ifstream ifs;
	ifs.open(ORDER_FILE,ios::in);

	string date;
	string interval;
	string stuid;
	string stuname;
	string roomid;
	string status;
	while (ifs>>date && ifs>>interval && ifs>>
		stuid && ifs>>stuname && ifs>> roomid && ifs
		>>status)
	{
		
		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");//4
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);

			m.insert(make_pair(key,value));
	 	}
		pos = interval.find(":");//4
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		pos = stuid.find(":");//4
		if (pos != -1)
		{
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		pos = stuname.find(":");//4
		if (pos != -1)
		{
			key = stuname.substr(0, pos);
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		pos = roomid.find(":");//4
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		pos = status.find(":");//4
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
	
	this->m_orderdata.insert(make_pair(this->m_size,m));
	this->m_size++;
	}
	ifs.close();
	//cout << this->m_orderdata[1]["date"]<<endl;

	
}
void OrderFile::updateOrder()
{
	if (this->m_size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE,ios::trunc);
	for(int i=0;i<this->m_size;i++)
	{
		ofs << "date:" << this->m_orderdata[i]["date"] << " ";
		ofs << "interval:" << this->m_orderdata[i]["interval"] << " ";
		ofs << "stuid:" << this->m_orderdata[i]["id"] << " ";
		ofs << "stuname:" << this->m_orderdata[i]["name"] << " ";
		ofs << "roomid:" << this->m_orderdata[i]["roomid"] << " ";
		ofs << "status:" << this->m_orderdata[i]["status"] << " ";
	}
	ofs.close();
}