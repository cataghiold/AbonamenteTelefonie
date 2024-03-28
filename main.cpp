#include<iostream>
#include<map>
using namespace std;


class Client {
private:
	long long int id;
	char tip_abonament;
	int nr_minute_folosite;
	int nr_sms_folosite;
	int nr_gb_folositi;
public:
	Client() {
		this->id = 0;
		this->tip_abonament = 'A';
		this->nr_minute_folosite = 0;
		this->nr_sms_folosite = 0;
		this->nr_gb_folositi = 0;
	}
	Client(long long int id, char tip_abonament, int nr_minute_folosite, int nr_sms_folosite, int nr_gb_folositi) {
		this->id = id;
		this->tip_abonament = tip_abonament;
		this->nr_minute_folosite = nr_minute_folosite;
		this->nr_sms_folosite = nr_sms_folosite;
		this->nr_gb_folositi = nr_gb_folositi;
	}
	long long int getId() {
		return this->id;
	}
	void setId(long long int id) {
		this->id = id;
	}
	char getTipAbonament() {
		return this->tip_abonament;
	}
	void setTipAbonament(char tip_abonament) {
		this->tip_abonament = tip_abonament;
	}
	int getNrMinuteFolosite() {
		return this->nr_minute_folosite;
	}
	void setNrMinuteFolosite(int nr_minute_folosite) {
		this->nr_minute_folosite = nr_minute_folosite;
	}
	int getNrSmsFolosite() {
		return this->nr_sms_folosite;
	}
	void setNrSmsFolosite(int nr_sms_folosite) {
		this->nr_sms_folosite = nr_sms_folosite;
	}
	int getNrGbFolositi() {
		return this->nr_gb_folositi;
	}
	void setNrGbFolositi(int nr_gb_folositi) {
		this->nr_gb_folositi = nr_gb_folositi;
	}
	friend istream& operator>> (istream& cin, Client& c)
	{

		long long id;
		char tip_abonament;
		int nr_minute_folosite, nr_sms_folosite, nr_gb_folositi;
		cin >> id >> tip_abonament >> nr_minute_folosite >> nr_sms_folosite >> nr_gb_folositi;
		c.setId(id);
		c.setTipAbonament(tip_abonament);
		c.setNrMinuteFolosite(nr_minute_folosite);
		c.setNrSmsFolosite(nr_sms_folosite);
		c.setNrGbFolositi(nr_gb_folositi);
		return cin;
	}
};

class Servicii {
protected:
	float cost;
	int nr_minute;
	int nr_sms;
	int nr_gb;
public:
	Servicii() {
		this->cost = 0.0f;
		this->nr_minute = 0;
		this->nr_sms = 0;
		this->nr_gb = 0;
	}
	Servicii(float cost, int nr_minute, int nr_sms, int nr_gb) {
		this->cost = cost;
		this->nr_minute = nr_minute;
		this->nr_sms = nr_sms;
		this->nr_gb = nr_gb;
	}
	float calculareCostSuplimentarMinute(int nr_minute_folosite, float cost_minut) {
		if (nr_minute_folosite > this->nr_minute)
			return cost_minut * (nr_minute_folosite - this->nr_minute);
		return 0;
	}
	float calculareCostSuplimentarSms(int nr_sms_folosite, float cost_sms) {
		if (nr_sms_folosite > this->nr_sms)
			return cost_sms * (nr_sms_folosite - this->nr_sms);
		return 0;
	}
	float calculareCostSuplimentarGb(int nr_gb_folositi, float cost_gb) {
		if (nr_gb_folositi > this->nr_gb)
			return cost_gb * (nr_gb_folositi - this->nr_gb);
		return 0;
	}
	virtual float calculareCostTotal(Client c) {
		return this->cost;
	}
};

class AbonamentStandard : public Servicii{
public:
	AbonamentStandard(float cost, int nr_minute, int nr_sms, int nr_gb) : Servicii(cost, nr_minute, nr_sms, nr_gb) {}
	float calculareCostTotal(Client c) {
		return
			this->cost +
			this->calculareCostSuplimentarMinute(c.getNrMinuteFolosite(), 0.1f) +
			this->calculareCostSuplimentarSms(c.getNrSmsFolosite(), 0.5f) +
			this->calculareCostSuplimentarGb(c.getNrGbFolositi(), 1.0f);

	}
};

class AbonamentStandardPlus : public Servicii {
public:
	AbonamentStandardPlus(float cost, int nr_minute, int nr_sms, int nr_gb) : Servicii(cost, nr_minute, nr_sms, nr_gb) {}
	float calculareCostTotal(Client c) {
		return
			this->cost +
			this->calculareCostSuplimentarMinute(c.getNrMinuteFolosite(), 0.15f) +
			this->calculareCostSuplimentarSms(c.getNrSmsFolosite(), 0.75f) +
			this->calculareCostSuplimentarGb(c.getNrGbFolositi(), 1.5f);

	}
};

bool mapContainsKey(map<long long int, float>& map, int key)
{
	if (map.find(key) == map.end()) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	map<long long int, float> costuri_clienti;
	float max_cost = 0.0f;
	long long int max_id = 0;
	for (int i = 0; i < n; i++)
	{
		Client c;
		cin >> c;
		long long int id_client = c.getId();
		Servicii* serviciu = nullptr;
		if (c.getTipAbonament() == 'A')
			serviciu = new AbonamentStandard(50, 100, 100, 10);
		else
			serviciu = new AbonamentStandardPlus(75, 200, 200, 15);
			
		if (!mapContainsKey(costuri_clienti, id_client))
			costuri_clienti.insert({ id_client, serviciu->calculareCostTotal(c) });
		else
			costuri_clienti[id_client] += serviciu->calculareCostTotal(c);
		delete serviciu;
	}

	for (map<long long int, float>::iterator it = costuri_clienti.begin(); it != costuri_clienti.end(); it++)
	{
		if (it->second > max_cost) {
			max_cost = it->second;
			max_id = it->first;
		}
	}

	cout << max_id << '\n';

	return 0;
}
