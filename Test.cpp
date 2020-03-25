#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "PhoneticFinder.hpp"

using namespace phonetic;

using namespace std;

TEST_CASE("Test PhoneticFind -> Sanity: simple example")
{

    CHECK(find(string("Dond vorri be haffy"), string("dont")).compare(string("Dond")) == 0);
    CHECK(find(string("Dond vorri be haffy"), string("worry")).compare(string("vorri")) == 0);
    CHECK(find(string("Dond vorri be haffy"), string("be")).compare(string("be")) == 0);
}

TEST_CASE("Test replacement of p and b")
{
    string text = "ppb happy bbbjk";
    CHECK(find(text, "happy").compare(string("happy")) == 0);
    CHECK(find(text, "habby").compare(string("happy")) == 0);
    CHECK(find(text, "hapby").compare(string("happy")) == 0);
    CHECK(find(text, "habpy").compare(string("happy")) == 0);
    CHECK(find(text, "ppb").compare(string("ppb")) == 0);
    CHECK(find(text, "ppp").compare(string("ppb")) == 0);
    CHECK(find(text, "bbbjk").compare(string("bbbjk")) == 0);
    CHECK(find(text, "pppjk").compare(string("bbbjk")) == 0);
    CHECK(find(text, "ppbjk").compare(string("bbbjk")) == 0);
    CHECK(find(text, "bppjk").compare(string("bbbjk")) == 0);
}

TEST_CASE("Test replacement of b and f")
{
    string text = "bake fabe bafi";

    CHECK(find(text, "bake").compare(string("bake")) == 0);
    CHECK(find(text, "fake").compare(string("bake")) == 0);
    CHECK(find(text, "fabe").compare(string("fabe")) == 0);
    CHECK(find(text, "bafe").compare(string("fabe")) == 0);
    CHECK(find(text, "babe").compare(string("fabe")) == 0);
    CHECK(find(text, "fafe").compare(string("fabe")) == 0);
    CHECK(find(text, "bafi").compare(string("bafi")) == 0);
    CHECK(find(text, "fabi").compare(string("bafi")) == 0);
    CHECK(find(text, "fafi").compare(string("bafi")) == 0);
    CHECK(find(text, "babi").compare(string("bafi")) == 0);
}

TEST_CASE("Test replacement of p and f")
{
    string text = "happy file people";

    CHECK(find(text, "happy").compare(string("happy")) == 0);
    CHECK(find(text, "haffy").compare(string("happy")) == 0);
    CHECK(find(text, "hapfy").compare(string("happy")) == 0);
    CHECK(find(text, "hafpy").compare(string("happy")) == 0);
    CHECK(find(text, "file").compare(string("file")) == 0);
    CHECK(find(text, "pile").compare(string("file")) == 0);
    CHECK(find(text, "people").compare(string("people")) == 0);
    CHECK(find(text, "feofle").compare(string("people")) == 0);
    CHECK(find(text, "feople").compare(string("people")) == 0);
    CHECK(find(text, "peofle").compare(string("people")) == 0);
}

TEST_CASE("Test replacement of c and k")
{
    string text = "calvin klein ck clock";

    CHECK(find(text, string("calvin")).compare(string("calvin")) == 0);
    CHECK(find(text, string("kalvin")).compare(string("calvin")) == 0);
    CHECK(find(text, string("klein")).compare(string("klein")) == 0);
    CHECK(find(text, string("clein")).compare(string("klein")) == 0);
    CHECK(find(text, string("ck")).compare(string("ck")) == 0);
    CHECK(find(text, string("cc")).compare(string("ck")) == 0);
    CHECK(find(text, string("kc")).compare(string("ck")) == 0);
    CHECK(find(text, string("kk")).compare(string("ck")) == 0);
    CHECK(find(text, string("clokk")).compare(string("clock")) == 0);
    CHECK(find(text, string("klock")).compare(string("clock")) == 0);
}

TEST_CASE("Test replacement of c and q")
{
    string text = "clock crazy qracu";

    CHECK(find(text, string("clock")).compare(string("clock")) == 0);
    CHECK(find(text, string("qloqk")).compare(string("clock")) == 0);
    CHECK(find(text, string("cloqk")).compare(string("clock")) == 0);
    CHECK(find(text, string("qlock")).compare(string("clock")) == 0);
    CHECK(find(text, string("crazy")).compare(string("crazy")) == 0);
    CHECK(find(text, string("qrazy")).compare(string("crazy")) == 0);
    CHECK(find(text, string("qracu")).compare(string("qracu")) == 0);
    CHECK(find(text, string("cracu")).compare(string("qracu")) == 0);
    CHECK(find(text, string("qraqu")).compare(string("qracu")) == 0);
    CHECK(find(text, string("craqu")).compare(string("qracu")) == 0);
}

TEST_CASE("Test replacement of q and k")
{
    string text = "cake qakl qoute kq";

    CHECK(find(text, string("cake")).compare(string("cake")) == 0);
    CHECK(find(text, string("caqe")).compare(string("cake")) == 0);
    CHECK(find(text, string("qakl")).compare(string("qakl")) == 0);
    CHECK(find(text, string("kake")).compare(string("cake")) == 0);
    CHECK(find(text, string("qaql")).compare(string("qakl")) == 0);
    CHECK(find(text, string("qakl")).compare(string("qakl")) == 0);
    CHECK(find(text, string("kaql")).compare(string("qakl")) == 0);
    CHECK(find(text, string("qoute")).compare(string("qoute")) == 0);
    CHECK(find(text, string("koute")).compare(string("qoute")) == 0);
    CHECK(find(text, string("qk")).compare(string("kq")) == 0);
}

TEST_CASE("Test replacement of v and w")
{
    string text = "im wery thankful wow wvv";
    CHECK(find(text, string("very")).compare(string("wery")) == 0);
    CHECK(find(text, string("wery")).compare(string("wery")) == 0);
    CHECK(find(text, string("wvv")).compare(string("wvv")) == 0);
    CHECK(find(text, string("vww")).compare(string("wvv")) == 0);
    CHECK(find(text, string("vvw")).compare(string("wvv")) == 0);
    CHECK(find(text, string("wwv")).compare(string("wvv")) == 0);
    CHECK(find(text, string("wvw")).compare(string("wvv")) == 0);
    CHECK(find(text, string("vwv")).compare(string("wvv")) == 0);
    CHECK(find(text, string("very")).compare(string("wery")) == 0);
    CHECK(find(text, string("vow")).compare(string("wow")) == 0);
}

TEST_CASE("Test replacement of g and j")
{

    string text = "joker is a good person gjg";

    CHECK(find(text, string("joker")).compare(string("joker")) == 0);
    CHECK(find(text, string("goker")).compare(string("joker")) == 0);
    CHECK(find(text, string("good")).compare(string("good")) == 0);
    CHECK(find(text, string("jood")).compare(string("good")) == 0);
    CHECK(find(text, string("gjg")).compare(string("gjg")) == 0);
    CHECK(find(text, string("jjj")).compare(string("gjg")) == 0);
    CHECK(find(text, string("ggg")).compare(string("gjg")) == 0);
    CHECK(find(text, string("jgj")).compare(string("gjg")) == 0);
    CHECK(find(text, string("jjg")).compare(string("gjg")) == 0);
    CHECK(find(text, string("ggj")).compare(string("gjg")) == 0);
}

TEST_CASE("Test replacement of s and z")
{
    string text = "what is the size of the dress";

    CHECK(find(text, string("iz")).compare(string("is")) == 0);
    CHECK(find(text, string("is")).compare(string("is")) == 0);
    CHECK(find(text, string("size")).compare(string("size")) == 0);
    CHECK(find(text, string("zize")).compare(string("size")) == 0);
    CHECK(find(text, string("sise")).compare(string("size")) == 0);
    CHECK(find(text, string("zise")).compare(string("size")) == 0);
    CHECK(find(text, string("dress")).compare(string("dress")) == 0);
    CHECK(find(text, string("drezz")).compare(string("dress")) == 0);
    CHECK(find(text, string("dresz")).compare(string("dress")) == 0);
    CHECK(find(text, string("drezs")).compare(string("dress")) == 0);
}

TEST_CASE("Test replacement of d and t")
{

    string text = "dont try to drive so fast";

    CHECK(find(text, string("dont")).compare(string("dont")) == 0);
    CHECK(find(text, string("dond")).compare(string("dont")) == 0);
    CHECK(find(text, string("tont")).compare(string("dont")) == 0);
    CHECK(find(text, string("tond")).compare(string("dont")) == 0);
    CHECK(find(text, string("dry")).compare(string("try")) == 0);
    CHECK(find(text, string("try")).compare(string("try")) == 0);
    CHECK(find(text, string("to")).compare(string("to")) == 0);
    CHECK(find(text, string("do")).compare(string("to")) == 0);
    CHECK(find(text, string("trive")).compare(string("drive")) == 0);
    CHECK(find(text, string("fasd")).compare(string("fast")) == 0);
}

TEST_CASE("Test replacement of o and u")
{
    string text = "i love you so much";

    CHECK(find(text, string("love")).compare(string("love")) == 0);
    CHECK(find(text, string("luve")).compare(string("love")) == 0);
    CHECK(find(text, string("you")).compare(string("you")) == 0);
    CHECK(find(text, string("yuu")).compare(string("you")) == 0);
    CHECK(find(text, string("yuo")).compare(string("you")) == 0);
    CHECK(find(text, string("yoo")).compare(string("you")) == 0);
    CHECK(find(text, string("so")).compare(string("so")) == 0);
    CHECK(find(text, string("su")).compare(string("so")) == 0);
    CHECK(find(text, string("much")).compare(string("much")) == 0);
    CHECK(find(text, string("moch")).compare(string("much")) == 0);
}

TEST_CASE("Test replacement of i and y")
{
    string text = "i like you yeli rely";

    CHECK(find(text, string("i")).compare(string("i")) == 0);
    CHECK(find(text, string("y")).compare(string("i")) == 0);
    CHECK(find(text, string("like")).compare(string("like")) == 0);
    CHECK(find(text, string("lyke")).compare(string("like")) == 0);
    CHECK(find(text, string("you")).compare(string("you")) == 0);
    CHECK(find(text, string("iou")).compare(string("you")) == 0);
    CHECK(find(text, string("yeli")).compare(string("yeli")) == 0);
    CHECK(find(text, string("iely")).compare(string("yeli")) == 0);
    CHECK(find(text, string("ieli")).compare(string("yeli")) == 0);
    CHECK(find(text, string("reli")).compare(string("rely")) == 0);
}

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "Happi rrr eee";
    CHECK(find(text, string("happi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("Happi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HAppi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HAPpi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HAPPi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HAPPI")).compare(string("Happi")) == 0);
    CHECK(find(text, string("hAPpI")).compare(string("Happi")) == 0);
    CHECK(find(text, string("happI")).compare(string("Happi")) == 0);
    CHECK(find(text, string("haPPi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HappI")).compare(string("Happi")) == 0);
}

TEST_CASE("Test replacement of lower-case and upper-case and replacement of p and f and b:")
{
    string text = "Happi rrr eee";

    CHECK(find(text, string("habpi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("Hafpi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HAffi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HAPfi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HABBi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HAFPI")).compare(string("Happi")) == 0);
    CHECK(find(text, string("hAPpI")).compare(string("Happi")) == 0);
    CHECK(find(text, string("habPI")).compare(string("Happi")) == 0);
    CHECK(find(text, string("haBPi")).compare(string("Happi")) == 0);
    CHECK(find(text, string("HafbI")).compare(string("Happi")) == 0);
}

// TEST_CASE("Test shorter word that is contained in a word in the text with upper case:")
// { //fails
//     string text = "Smile xxx yyy";
//     CHECK(find(text, string("SMIL")).compare(string("Happi")) == 0);
//     CHECK(find(text, string("SMI")).compare(string("Happi")) == 0);
//     CHECK(find(text, string("SM")).compare(string("Happi")) == 0);
//     CHECK(find(text, string("S")).compare(string("Happi")) == 0);
// }

// TEST_CASE("Test shorter word that is contained in a word in the text:")
// { //fails
//     string text = "phsyco xxx yyy";
//     CHECK(find(text, string("phsyc")).compare(string("compute")) == 0);
//     CHECK(find(text, string("phsy")).compare(string("compute")) == 0);
//     CHECK(find(text, string("phs")).compare(string("compute")) == 0);
//     CHECK(find(text, string("ph")).compare(string("compute")) == 0);
//     CHECK(find(text, string("p")).compare(string("compute")) == 0);
//     CHECK(find(text, string("h")).compare(string("compute")) == 0);
//     CHECK(find(text, string("")).compare(string("compute")) == 0);
// }

TEST_CASE("Test PhoneticFind -> More than one spelling error")
{
    string text = "Y luwe tuj bor sure";
    CHECK(find(text, string("dog")).compare(string("tuj")) == 0);
    CHECK(find(text, string("for")).compare(string("bor")) == 0);
    CHECK(find(text, string("love")).compare(string("luwe")) == 0);
    CHECK(find(text, string("i")).compare(string("Y")) == 0);
}

// // TEST_CASE("Test PhoneticFind ->  Not Alaphbet letters")
// // {
// //     CHECK(find(string("dog"),string("$#@@ #% ^7")).compare(string("^7"))==0);
// // }

// // TEST_CASE("Test PhoneticFind -> No spelling errors at all")
// // {
// //     string text = "Test the case that there are no spelling errors at all";

// //     CHECK(find(string("Test"), text).compare(string("Test")) == 0);
// //     CHECK(find(string("the"), text).compare(string("the")) == 0);
// //     CHECK(find(string("case"), text).compare(string("case")) == 0);
// //     CHECK(find(string("that"), text).compare(string("that")) == 0);
// //     CHECK(find(string("there"), text).compare(string("there")) == 0);
// //     CHECK(find(string("are"), text).compare(string("are")) == 0);
// //     CHECK(find(string("no"), text).compare(string("no")) == 0);
// //     CHECK(find(string("spelling"), text).compare(string("spelling")) == 0);
// //     CHECK(find(string("errors"), text).compare(string("errors")) == 0);
// //     CHECK(find(string("at"), text).compare(string("at")) == 0);
// //     CHECK(find(string("all"), text).compare(string("all")) == 0);
// // }

// TEST_CASE("Test not equals")
// { //fails
//     string text = "very xxx yyy";
//     CHECK(find(text, "cery") == string("very"));
//     CHECK(find(text, "veryy") == string("very"));
//     CHECK(find(text, "veery") == string("very"));
//     CHECK(find(text, "ver") == string("very"));
// }

// TEST_CASE("Test PhoneticFind -> if the string is empy")
// {
//     string text = " ";
//     CHECK(find(text,string("love") ).compare("love") == 0); //fail
// }
