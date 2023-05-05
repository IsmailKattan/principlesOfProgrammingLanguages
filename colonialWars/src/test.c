#include <flag.h>
#include <tactic/tacticA.h>
#include <tactic/tacticB.h>
#include <tactic/tacticC.h>


int main() {



  return 0;
}



/*
-------------------------------------------------------------------------------------------------------------------
*/
/*
test for tacticC
  TacticC T3 = new_TacticC(213,"C taktiği");
  printf("%d\n",T3->getTactic(T3));
  printf("%d\n ",T3->getTactic(T3)->getID(T3->getTactic(T3)));
  printf("%s\n",T3->getTactic(T3)->getName(T3->getTactic(T3)));
  printf("savaş!!! : %d\n", T3->war(T3));
  T3->delete(T3);
*/

/*
test for tacticB
  TacticB T2 = new_TacticB(321,"B taktiği");
  printf("%d\n",T2->getTactic(T2));
  printf("%d\n ",T2->getTactic(T2)->getID(T2->getTactic(T2)));
  printf("%s\n",T2->getTactic(T2)->getName(T2->getTactic(T2)));
  printf("savaş!!! : %d\n", T2->war(T2));
  T2->delete(T2);
*/

/*
test for tacticA
  TacticA T1 = new_TacticA(123,"A taktiği");
  printf("%d\n",T1->getTactic(T1));
  printf("%d\n ",T1->getTactic(T1)->getID(T1->getTactic(T1)));
  printf("%s\n",T1->getTactic(T1)->getName(T1->getTactic(T1)));
  printf("savaş!!! : %d\n", T1->war(T1));
  T1->delete(T1);
*/

/*
----------------------------------------------------------------------------------------------------------------------
*/
/*

  test for tactic
  Tactic T1 = new_Tactic(1,"ismailin taktiği");
  Tactic T2 = new_Tactic(2,"ibrahimin taktiği");
  Tactic T3 = new_Tactic(3,"kadirin taktiği");
  Tactic T4 = new_Tactic(4,"muhammedin taktiği");
  Tactic tactic[4] = {T1,T2,T3,T4};
  printf("%d\n",tactic);
  printf("%d\n",sizeof(tactic));

  for(size_t i = 0 ; i < sizeof(tactic) / sizeof(Tactic);i++)
  {
    printf("%d\n",tactic[i]->getID(tactic[i]));
    printf("%s\n",tactic[i]->getName(tactic[i]));
    printf("savaş!!! : %d\n", tactic[i]->War(tactic[i]));
  }

  for(size_t i = 0 ; i < sizeof(tactic) / sizeof(Tactic);i++)
  {
    tactic[i]->delete(tactic[i]);
  }
*/

/*
---------------------------------------------------------------------------------------------------------------------
*/
/*

  test for Flag;
  Flag f = new_Flag('f');
  Flag l = new_Flag('l');
  Flag a = new_Flag('a');
  Flag g = new_Flag('g');
  Flag flag[4] = {f, l, a, g};
  printf("%d\n", flag);

  for (size_t i = 0; i < sizeof(flag) / sizeof(Flag); i++)
  {
    printf("%c\n", flag[i]->getFlg(flag[i]));
  }

  for (size_t i = 0; i < sizeof(flag) / sizeof(Flag); i++)
  {
    flag[i]->delete(flag[i]);
  }*/