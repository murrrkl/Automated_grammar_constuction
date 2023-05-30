#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//Пол
PolName -> Word<kwtype=pol>;
//Мед. учреждение
hospitalW -> 'врач'|'доктор'|'лечение'|'госпиталь'|'больница'|'поликлиника'|'диета';
PP -> Prep hospitalW;
med -> Verb PP;
//Вес
WeightW -> 'сантиметр'|'килограмм';
WeightSokr -> 'см'|'кг';
Weight -> 'вес';
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
WeightZn -> Count WeightW;
WeightZn -> Count WeightSokr;
WeightZn -> AnyWord Count WeightW;
WeightZn -> AnyWord Count WeightSokr;
WeightZn -> Adj Weight;
//Возраст
AgeW-> 'год'|'лет';
AgeNum -> AnyWord<wff=/[1-9]?[0-9]-?((ый)|(ть)|(ой))?/>;

Age -> AgeNum AgeW;

//1

S -> Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.Ves) AnyWord* PolName interp (Situation_first.Pol) AnyWord* med interp(Situation_first.Med);
S -> Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.Ves) AnyWord* med interp(Situation_first.Med) AnyWord* PolName interp (Situation_first.Pol);
S -> Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.Med) AnyWord*  WeightZn interp(Situation_first.Ves) AnyWord* PolName interp (Situation_first.Pol);
S -> Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.Med) AnyWord* PolName interp (Situation_first.Pol)  AnyWord* WeightZn interp(Situation_first.Ves);
S -> Age interp(Situation_first.Age) AnyWord* PolName interp (Situation_first.Pol) AnyWord* med interp(Situation_first.Med) AnyWord*  WeightZn interp(Situation_first.Ves) ;
S -> Age interp(Situation_first.Age) AnyWord* PolName interp (Situation_first.Pol) AnyWord* WeightZn interp(Situation_first.Ves)  AnyWord*  med interp(Situation_first.Med);

//2
S -> WeightZn interp(Situation_first.Ves) AnyWord* Age interp(Situation_first.Age)  AnyWord* PolName interp (Situation_first.Pol) AnyWord* med interp(Situation_first.Med);
S -> WeightZn interp(Situation_first.Ves) AnyWord* Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.Med) AnyWord* PolName interp (Situation_first.Pol);
S ->  med interp(Situation_first.Med) AnyWord* Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.Ves) AnyWord* PolName interp (Situation_first.Pol);
S -> med interp(Situation_first.Med) AnyWord* Age interp(Situation_first.Age) AnyWord* PolName interp (Situation_first.Pol)  AnyWord* WeightZn interp(Situation_first.Ves);
S ->  PolName interp (Situation_first.Pol) AnyWord* Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.Med) AnyWord*  WeightZn interp(Situation_first.Ves) ;
S -> PolName interp (Situation_first.Pol) AnyWord* Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.Ves)  AnyWord*  med interp(Situation_first.Med);

//3

S -> WeightZn interp(Situation_first.Ves) AnyWord* PolName interp (Situation_first.Pol) AnyWord* Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.Med);
S -> WeightZn interp(Situation_first.Ves) AnyWord* med interp(Situation_first.Med) AnyWord* Age interp(Situation_first.Age) AnyWord* PolName interp (Situation_first.Pol);
S -> med interp(Situation_first.Med) AnyWord*  WeightZn interp(Situation_first.Ves) AnyWord* Age interp(Situation_first.Age) AnyWord* PolName interp (Situation_first.Pol);
S -> med interp(Situation_first.Med) AnyWord* PolName interp (Situation_first.Pol)  AnyWord* Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.Ves);
S -> PolName interp (Situation_first.Pol) AnyWord* med interp(Situation_first.Med) AnyWord*  Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.Ves) ;
S -> PolName interp (Situation_first.Pol) AnyWord* WeightZn interp(Situation_first.Ves)  AnyWord*  Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.Med);


//4
S -> WeightZn interp(Situation_first.Ves) AnyWord* PolName interp (Situation_first.Pol) AnyWord* med interp(Situation_first.Med)AnyWord* Age interp(Situation_first.Age);
S -> WeightZn interp(Situation_first.Ves) AnyWord* med interp(Situation_first.Med) AnyWord* PolName interp (Situation_first.Pol) AnyWord* Age interp(Situation_first.Age);
S -> med interp(Situation_first.Med) AnyWord*  WeightZn interp(Situation_first.Ves) AnyWord* PolName interp (Situation_first.Pol) AnyWord* Age interp(Situation_first.Age);
S -> med interp(Situation_first.Med) AnyWord* PolName interp (Situation_first.Pol)  AnyWord* WeightZn interp(Situation_first.Ves)AnyWord* Age interp(Situation_first.Age);
S -> PolName interp (Situation_first.Pol) AnyWord* med interp(Situation_first.Med) AnyWord*  WeightZn interp(Situation_first.Ves) AnyWord* Age interp(Situation_first.Age);
S -> PolName interp (Situation_first.Pol) AnyWord* WeightZn interp(Situation_first.Ves)  AnyWord*  med interp(Situation_first.Med) AnyWord* Age interp(Situation_first.Age);





