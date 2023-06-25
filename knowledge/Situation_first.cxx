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

