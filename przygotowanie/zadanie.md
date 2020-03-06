zaimplementowac baterie

class battery
      int m_capacity // pojemnosc baterii w mAh DEFAULT 4000
      int m_amount // bateria w mAh
      int m_percent // bateria w % (od 0 do 100)

      battery(int input) //stan poczatkowy
      battery(int input,int capacity) //stan poczatkowy, pojemnosc

      void status() //wypisz ile z ilu,% baterii
      int getCharge() //zwroc dostepna ilosc (w mAh)
      
      bool drain(int amount) //rozladowac baterie o amount
      int chargeup(int amount) //ladowanie baterii o amount, zwrocic pozostale po wypelnieniu

operatory:
	+ zwraca nowa baterie o wiekszej pojemnosci z suma dwoch baterii i wyczerpuje te co stworzyly
	-= wyczerpuje baterie po prawo by wypelnic ta po lewo np. b1 -= b2; b1 jest suma, b2 jest co pozostalo
	+= wyczerpuje baterie po lewo by wypelnic ta po lewo np. b1 += b2; b1 jest co pozostalo, b2 jest suma
	* balansuje dwie baterie
wyjatki:
	gdy chcemy pobrac z pustej baterii
	gdy chcemy pobrac wiecej niz ma bateria
	jezeli argumenty funkcji sa ujemne


klasa dziedziczna

class protectedBattery
      int m_threshold (od 0 do 100) jaki jest minimalny stan baterii po ktorej nie mozna dalej pobierac

      protectedBattery(int amount, int capacity, int thershold) //stan poczatkowy, pojemnosc, ochrona bateri w procentach
      getCharge() ma zwracac tyle ile faktycznie mozemy uzyc teraz amount - %threshold


