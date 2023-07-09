#encoding "utf-8"
#GRAMMAR_ROOT S

PolName -> Word<kwtype=pol>;

hospitalW -> 'врач'|'доктор'|'лечение'|'госпиталь'|'больница'|'поликлиника'|'диета';
PP -> Prep hospitalW;
med -> Verb PP;

WeightW -> 'сантиметр'|'килограмм';
WeightSokr -> 'см'|'кг';
Weight -> 'вес';
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
WeightZn -> Count WeightW;
WeightZn -> Count WeightSokr;
WeightZn -> AnyWord Count WeightW;
WeightZn -> AnyWord Count WeightSokr;
WeightZn -> Adj Weight;

AgeW-> 'год'|'лет';
AgeNum -> AnyWord<wff=/[1-9]?[0-9]-?((ый)|(ть)|(ой))?/>;

Age -> AgeNum AgeW;

S -> PolName interp(Situation_first.PolName) AnyWord* Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* med interp(Situation_first.med) AnyWord* ;
S -> Age interp(Situation_first.Age) AnyWord* PolName interp(Situation_first.PolName) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* med interp(Situation_first.med) AnyWord* ;
S -> PolName interp(Situation_first.PolName) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.med) AnyWord* ;
S -> WeightZn interp(Situation_first.WeightZn) AnyWord* PolName interp(Situation_first.PolName) AnyWord* Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.med) AnyWord* ;
S -> Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* PolName interp(Situation_first.PolName) AnyWord* med interp(Situation_first.med) AnyWord* ;
S -> WeightZn interp(Situation_first.WeightZn) AnyWord* Age interp(Situation_first.Age) AnyWord* PolName interp(Situation_first.PolName) AnyWord* med interp(Situation_first.med) AnyWord* ;
S -> PolName interp(Situation_first.PolName) AnyWord* Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.med) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* ;
S -> Age interp(Situation_first.Age) AnyWord* PolName interp(Situation_first.PolName) AnyWord* med interp(Situation_first.med) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* ;
S -> PolName interp(Situation_first.PolName) AnyWord* med interp(Situation_first.med) AnyWord* Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* ;
S -> med interp(Situation_first.med) AnyWord* PolName interp(Situation_first.PolName) AnyWord* Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* ;
S -> Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.med) AnyWord* PolName interp(Situation_first.PolName) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* ;
S -> med interp(Situation_first.med) AnyWord* Age interp(Situation_first.Age) AnyWord* PolName interp(Situation_first.PolName) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* ;
S -> PolName interp(Situation_first.PolName) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* med interp(Situation_first.med) AnyWord* Age interp(Situation_first.Age) AnyWord* ;
S -> WeightZn interp(Situation_first.WeightZn) AnyWord* PolName interp(Situation_first.PolName) AnyWord* med interp(Situation_first.med) AnyWord* Age interp(Situation_first.Age) AnyWord* ;
S -> PolName interp(Situation_first.PolName) AnyWord* med interp(Situation_first.med) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* Age interp(Situation_first.Age) AnyWord* ;
S -> med interp(Situation_first.med) AnyWord* PolName interp(Situation_first.PolName) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* Age interp(Situation_first.Age) AnyWord* ;
S -> WeightZn interp(Situation_first.WeightZn) AnyWord* med interp(Situation_first.med) AnyWord* PolName interp(Situation_first.PolName) AnyWord* Age interp(Situation_first.Age) AnyWord* ;
S -> med interp(Situation_first.med) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* PolName interp(Situation_first.PolName) AnyWord* Age interp(Situation_first.Age) AnyWord* ;
S -> Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* med interp(Situation_first.med) AnyWord* PolName interp(Situation_first.PolName) AnyWord* ;
S -> WeightZn interp(Situation_first.WeightZn) AnyWord* Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.med) AnyWord* PolName interp(Situation_first.PolName) AnyWord* ;
S -> Age interp(Situation_first.Age) AnyWord* med interp(Situation_first.med) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* PolName interp(Situation_first.PolName) AnyWord* ;
S -> med interp(Situation_first.med) AnyWord* Age interp(Situation_first.Age) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* PolName interp(Situation_first.PolName) AnyWord* ;
S -> WeightZn interp(Situation_first.WeightZn) AnyWord* med interp(Situation_first.med) AnyWord* Age interp(Situation_first.Age) AnyWord* PolName interp(Situation_first.PolName) AnyWord* ;
S -> med interp(Situation_first.med) AnyWord* WeightZn interp(Situation_first.WeightZn) AnyWord* Age interp(Situation_first.Age) AnyWord* PolName interp(Situation_first.PolName) AnyWord* ;
