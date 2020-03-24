#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "PhoneticFinder.hpp"

using namespace phonetic;

using namespace std;

TEST_CASE("Test PhoneticFind -> Sanity: simple example")
{

    CHECK(find(string("dont"), string("Dond vorri be haffy")).compare(string("Dond")) == 0);
    CHECK(find(string("worry"), string("Dond vorri be haffy")).compare(string("vorri")) == 0);
    CHECK(find(string("be"), string("Dond vorri be haffy")).compare(string("be")) == 0);
}

TEST_CASE("Test replacement of p and b")
{
    string text = "ppb happy bbbjk";
    CHECK(find("happy", text).compare(string("happy")) == 0);
    CHECK(find("habby", text).compare(string("happy")) == 0);
    CHECK(find("hapby", text).compare(string("happy")) == 0);
    CHECK(find("habpy", text).compare(string("happy")) == 0);
    CHECK(find("ppb", text).compare(string("ppb")) == 0);
    CHECK(find("ppp", text).compare(string("ppb")) == 0);
    CHECK(find("bbbjk", text).compare(string("bbbjk")) == 0);
    CHECK(find("pppjk", text).compare(string("bbbjk")) == 0);
    CHECK(find("ppbjk", text).compare(string("bbbjk")) == 0);
    CHECK(find("bppjk", text).compare(string("bbbjk")) == 0);
}

TEST_CASE("Test replacement of b and f")
{
    string text = "bake fabe bafi";

    CHECK(find("bake", text).compare(string("bake")) == 0);
    CHECK(find("fake", text).compare(string("bake")) == 0);
    CHECK(find("fabe", text).compare(string("fabe")) == 0);
    CHECK(find("bafe", text).compare(string("fabe")) == 0);
    CHECK(find("babe", text).compare(string("fabe")) == 0);
    CHECK(find("fafe", text).compare(string("fabe")) == 0);
    CHECK(find("bafi", text).compare(string("bafi")) == 0);
    CHECK(find("fabi", text).compare(string("bafi")) == 0);
    CHECK(find("fafi", text).compare(string("bafi")) == 0);
    CHECK(find("babi", text).compare(string("bafi")) == 0);
}

TEST_CASE("Test replacement of p and f")
{
    string text = "happy file people";

    CHECK(find("happy", text).compare(string("happy")) == 0);
    CHECK(find("haffy", text).compare(string("happy")) == 0);
    CHECK(find("hapfy", text).compare(string("happy")) == 0);
    CHECK(find("hafpy", text).compare(string("happy")) == 0);
    CHECK(find("file", text).compare(string("file")) == 0);
    CHECK(find("pile", text).compare(string("file")) == 0);
    CHECK(find("people", text).compare(string("people")) == 0);
    CHECK(find("feofle", text).compare(string("people")) == 0);
    CHECK(find("feople", text).compare(string("people")) == 0);
    CHECK(find("peofle", text).compare(string("people")) == 0);
}

TEST_CASE("Test replacement of c and k")
{
    string text = "calvin klein ck clock";

    CHECK(find("calvin", text) == string("calvin"));
    CHECK(find("kalvin", text) == string("calvin"));
    CHECK(find("klein", text) == string("klein"));
    CHECK(find("clein", text) == string("klein"));
    CHECK(find("ck", text) == string("ck"));
    CHECK(find("cc", text) == string("ck"));
    CHECK(find("kc", text) == string("ck"));
    CHECK(find("kk", text) == string("ck"));
    CHECK(find("clokk", text) == string("clock"));
    CHECK(find("klock", text) == string("clock"));
}

TEST_CASE("Test replacement of c and q")
{
    string text = "clock crazy qracu";

    CHECK(find("clock", text).compare(string("clock"))==0);
    CHECK(find("qloqk", text).compare(string("clock"))==0);
    CHECK(find("cloqk", text) == string("clock"))==0);
    CHECK(find("qlock", text) == string("clock"))==0);
    CHECK(find("crazy", text) == string("crazy"))==0);
    CHECK(find("qrazy", text) == string("crazy"))==0);
    CHECK(find("qracu", text) == string("qracu"))==0);
    CHECK(find("cracu", text) == string("qracu"))==0);
    CHECK(find("qraqu", text) == string("qracu"))==0);
    CHECK(find("craqu", text) == string("qracu"))==0);
}

TEST_CASE("Test replacement of q and k")
{
    string text = "cake qake qoute kq";

    CHECK(find("cake", text) == string("cake"));
    CHECK(find("caqe", text) == string("cake"));
    CHECK(find("qake", text) == string("qake"));
    CHECK(find("kake", text) == string("qake"));
    CHECK(find("qaqe", text) == string("qake"));
    CHECK(find("qake", text) == string("qake"));
    CHECK(find("kaqe", text) == string("qake"));
    CHECK(find("qoute", text) == string("qoute"));
    CHECK(find("koute", text) == string("qoute"));
    CHECK(find("qk", text) == string("kq"));
}

TEST_CASE("Test replacement of v and w")
{
    string text = "im wery thankful wow wvv";
    CHECK(find("very", text) == string("wery"));
    CHECK(find("wery", text) == string("wery"));
    CHECK(find("wvv", text) == string("wvv"));
    CHECK(find("vww", text) == string("wvv"));
    CHECK(find("vvw", text) == string("wvv"));
    CHECK(find("wwv", text) == string("wvv"));
    CHECK(find("wvw", text) == string("wvv"));
    CHECK(find("vwv", text) == string("wvv"));
    CHECK(find("very", text) == string("wery"));
    CHECK(find("vow", text) == string("wow"));
}

TEST_CASE("Test replacement of g and j")
{

    string text = "joker is a good person gjg";

    CHECK(find("joker", text) == string("joker"));
    CHECK(find("goker", text) == string("joker"));
    CHECK(find("good", text) == string("good"));
    CHECK(find("jood", text) == string("good"));
    CHECK(find("gjg", text) == string("gjg"));
    CHECK(find("jjj", text) == string("gjg"));
    CHECK(find("ggg", text) == string("gjg"));
    CHECK(find("jgj", text) == string("gjg"));
    CHECK(find("jjg", text) == string("gjg"));
    CHECK(find("ggj", text) == string("gjg"));
}

TEST_CASE("Test replacement of s and z")
{
    string text = "what is the size of the dress?";

    CHECK(find("iz", text) == string("is"));
    CHECK(find("is", text) == string("is"));
    CHECK(find("size", text) == string("size"));
    CHECK(find("zize", text) == string("size"));
    CHECK(find("sise", text) == string("size"));
    CHECK(find("zise", text) == string("size"));
    CHECK(find("dress", text) == string("dress"));
    CHECK(find("drezz", text) == string("dress"));
    CHECK(find("dresz", text) == string("dress"));
    CHECK(find("drezs", text) == string("dress"));
}

TEST_CASE("Test replacement of d and t")
{

    string text = "dont try to drive so fast";

    CHECK(find("dont", text) == string("dont"));
    CHECK(find("dond", text) == string("dont"));
    CHECK(find("tont", text) == string("dont"));
    CHECK(find("tond", text) == string("dont"));
    CHECK(find("dry", text) == string("try"));
    CHECK(find("try", text) == string("try"));
    CHECK(find("to", text) == string("to"));
    CHECK(find("do", text) == string("to"));
    CHECK(find("trive", text) == string("drive"));
    CHECK(find("fasd", text) == string("fast"));
}

TEST_CASE("Test replacement of o and u")
{
    string text = "i love you so much";

    CHECK(find("love", text) == string("love"));
    CHECK(find("luve", text) == string("love"));
    CHECK(find("you", text) == string("you"));
    CHECK(find("yuu", text) == string("you"));
    CHECK(find("yuo", text) == string("you"));
    CHECK(find("yoo", text) == string("you"));
    CHECK(find("so", text) == string("so"));
    CHECK(find("su", text) == string("so"));
    CHECK(find("much", text) == string("much"));
    CHECK(find("moch", text) == string("much"));
}

TEST_CASE("Test replacement of i and y")
{
    string text = "i like you yeli rely";

    CHECK(find("i", text) == string("i"));
    CHECK(find("y", text) == string("i"));
    CHECK(find("like", text) == string("like"));
    CHECK(find("lyke", text) == string("like"));
    CHECK(find("you", text) == string("you"));
    CHECK(find("iou", text) == string("you"));
    CHECK(find("yeli", text) == string("yeli"));
    CHECK(find("iely", text) == string("yeli"));
    CHECK(find("ieli", text) == string("yeli"));
    CHECK(find("reli", text) == string("rely"));
}

TEST_CASE("Test replacement of lower-case and upper-case")
{
    string text = "Happi rrr eee";
    CHECK(find("happi", text) == string("Happi"));
    CHECK(find("Happi", text) == string("Happi"));
    CHECK(find("HAppi", text) == string("Happi"));
    CHECK(find("HAPpi", text) == string("Happi"));
    CHECK(find("HAPPi", text) == string("Happi"));
    CHECK(find("HAPPI", text) == string("Happi"));
    CHECK(find("hAPpI", text) == string("Happi"));
    CHECK(find("happI", text) == string("Happi"));
    CHECK(find("haPPi", text) == string("Happi"));
    CHECK(find("HappI", text) == string("Happi"));
}

TEST_CASE("Test replacement of lower-case and upper-case and replacement of p and f and b:")
{
    string text = "Happi rrr eee";
    CHECK(find("habpi", text) == string("Happi"));
    CHECK(find("Hafpi", text) == string("Happi"));
    CHECK(find("HAffi", text) == string("Happi"));
    CHECK(find("HAPfi", text) == string("Happi"));
    CHECK(find("HABBi", text) == string("Happi"));
    CHECK(find("HAFPI", text) == string("Happi"));
    CHECK(find("hAPpI", text) == string("Happi"));
    CHECK(find("habPI", text) == string("Happi"));
    CHECK(find("haBPi", text) == string("Happi"));
    CHECK(find("HafbI", text) == string("Happi"));
}

TEST_CASE("Test shorter word that is contained in a word in the text with upper case:")
{ //fails
    string text = "Smile xxx yyy";
    CHECK(find(text, "SMIL") == string("Happi"));
    CHECK(find(text, "SMI") == string("Happi"));
    CHECK(find(text, "SM") == string("Happi"));
    CHECK(find(text, "S") == string("Happi"));
}

TEST_CASE("Test shorter word that is contained in a word in the text:")
{ //fails
    string text = "phsyco xxx yyy";
    CHECK(find(text, "phsyc") == string("compute"));
    CHECK(find(text, "phsy") == string("compute"));
    CHECK(find(text, "phs") == string("compute"));
    CHECK(find(text, "ph") == string("compute"));
    CHECK(find(text, "p") == string("compute"));
    CHECK(find(text, "h") == string("compute"));
    CHECK(find(text, "") == string("compute"));
}

TEST_CASE("Test PhoneticFind -> More than one spelling error")
{
    CHECK(find(string("dog"), string("Y luwe tuj bor sure")) == string("tuj"));
    CHECK(find(string("for"), string("Y luwe tuj bor sure")) == string("bor"));
    CHECK(find(string("love"), string("Y luwe tuj bor sure")) == string("luwe"));
    CHECK(find(string("i"), string("Y luwe tuj bor sure")) == string("luwe"));
}

// TEST_CASE("Test PhoneticFind ->  Not Alaphbet letters")
// {
//     CHECK(find(string("dog"),string("$#@@ #% ^7")).compare(string("^7"))==0);
// }

// TEST_CASE("Test PhoneticFind -> No spelling errors at all")
// {
//     string text = "Test the case that there are no spelling errors at all";

//     CHECK(find(string("Test"), text).compare(string("Test")) == 0);
//     CHECK(find(string("the"), text).compare(string("the")) == 0);
//     CHECK(find(string("case"), text).compare(string("case")) == 0);
//     CHECK(find(string("that"), text).compare(string("that")) == 0);
//     CHECK(find(string("there"), text).compare(string("there")) == 0);
//     CHECK(find(string("are"), text).compare(string("are")) == 0);
//     CHECK(find(string("no"), text).compare(string("no")) == 0);
//     CHECK(find(string("spelling"), text).compare(string("spelling")) == 0);
//     CHECK(find(string("errors"), text).compare(string("errors")) == 0);
//     CHECK(find(string("at"), text).compare(string("at")) == 0);
//     CHECK(find(string("all"), text).compare(string("all")) == 0);
// }

TEST_CASE("Test PhoneticFind -> Word not found")
{
    string text = "live laugh love";
    CHECK(find(string("hi"), text).compare(NULL) == 0);
    CHECK(find(string("bye"), text).compare(string(NULL)) == 0);
    CHECK(find(string("lime"), text).compare(string(NULL)) == 0);
    CHECK(find(string("lode"), text).compare(string(NULL)) == 0);
    CHECK(find(string("lauke"), text).compare(string(NULL)) == 0);
    CHECK(find(string("bive"), text).compare(string(NULL)) == 0);
    CHECK(find(string("the"), text).compare(string(NULL)) == 0);
    CHECK(find(string("word"), text).compare(string(NULL)) == 0);
    CHECK(find(string("not"), text).compare(string(NULL)) == 0);
    CHECK(find(string("found"), text).compare(string(NULL)) == 0);
}

TEST_CASE("Test PhoneticFind -> if the string is NULL")
{
    string text = " ";
    CHECK(find(string(" "), text).compare(" ") == 0);
}
