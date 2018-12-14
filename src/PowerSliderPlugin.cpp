#include "PowerSliderPlugin.hpp"
#include "PowerSlider.hpp"

PowerSliderPlugin::PowerSliderPlugin(QObject *parent) : QObject(parent) {
  initialized = false;
}

void PowerSliderPlugin::initialize(QDesignerFormEditorInterface * /*core*/) {
  if (initialized)
    return;
  initialized = true;
}

bool PowerSliderPlugin::isInitialized() const { return initialized; }

QWidget *PowerSliderPlugin::createWidget(QWidget *parent) {
  return new PowerSlider(parent);
}

QString PowerSliderPlugin::name() const { return QLatin1String("PowerSlider"); }

QString PowerSliderPlugin::group() const {
  return QLatin1String("Input Widgets");
}

QIcon PowerSliderPlugin::icon() const {

  /* XPM */
  static const char *icon_xpm[] = {
      /* columns rows colors chars-per-pixel */
      "32 32 221 2", "   c black", ".  c #000101", "X  c #000304",
      "o  c #00090A", "O  c #000D0E", "+  c #000F11", "@  c #001114",
      "#  c #001316", "$  c #00171B", "%  c #00181C", "&  c #002228",
      "*  c #00272F", "=  c #002C34", "-  c #003039", ";  c #00353A",
      ":  c #00353E", ">  c #003741", ",  c #003842", "<  c #003A44",
      "1  c #003B46", "2  c #003C47", "3  c #003C48", "4  c #003E49",
      "5  c #00404B", "6  c #00404C", "7  c #00414D", "8  c #00424D",
      "9  c #00424E", "0  c #00434F", "q  c #004752", "w  c #004754",
      "e  c #004A57", "r  c #004E59", "t  c #004C5A", "y  c #004E5C",
      "u  c #004F5D", "i  c #00545E", "p  c #005362", "a  c #005761",
      "s  c #005767", "d  c #005B6B", "f  c #005B6C", "g  c #005C6C",
      "h  c #005D6E", "j  c #005E6F", "k  c #005F71", "l  c #006071",
      "z  c #006274", "x  c #006375", "c  c #006475", "v  c #006476",
      "b  c #006577", "n  c #006678", "m  c #006679", "M  c #00687B",
      "N  c #00687C", "B  c #006A7D", "V  c #006B7E", "C  c #006C81",
      "Z  c #016F81", "A  c #006E82", "S  c #006F82", "D  c #006F83",
      "F  c #007082", "G  c #007084", "H  c #007388", "J  c #00758A",
      "K  c #00758B", "L  c #00788D", "P  c #007A91", "I  c #007B91",
      "U  c #007C92", "Y  c #007D94", "T  c #007F96", "R  c #008097",
      "E  c #008595", "W  c #008098", "Q  c #008198", "!  c #00839A",
      "~  c #00849C", "^  c #00859D", "/  c #00869D", "(  c #00869E",
      ")  c #00879F", "_  c #0087A0", "`  c #0089A0", "'  c #0088A1",
      "]  c #0089A1", "[  c #008AA1", "{  c #008BA2", "}  c #008AA3",
      "|  c #008BA3", " . c #008CA3", ".. c #008BA4", "X. c #008DA4",
      "o. c #008CA5", "O. c #008EA8", "+. c #008FA8", "@. c #0096A7",
      "#. c #0090AA", "$. c #0091AB", "%. c #0093AB", "&. c #0094AA",
      "*. c #0092AC", "=. c #0093AD", "-. c #0094AF", ";. c #0096AE",
      ":. c #0097AE", ">. c #1996A4", ",. c #0095B0", "<. c #0096B2",
      "1. c #0097B2", "2. c #0098B3", "3. c #009AB3", "4. c #0098B4",
      "5. c #0099B4", "6. c #0099B5", "7. c #009AB5", "8. c #009AB6",
      "9. c #009BB7", "0. c #009BB8", "q. c #009CB8", "w. c #009DB9",
      "e. c #009EB9", "r. c #009DBA", "t. c #009EBA", "y. c #009FBA",
      "u. c #009FBB", "i. c #00A2BB", "p. c #00A1BC", "a. c #00A2BD",
      "s. c #00A3BD", "d. c #00A4BC", "f. c #00A5BC", "g. c #00A4BE",
      "h. c #00A4BF", "j. c #00A5BF", "k. c #00A5C0", "l. c #00A7C0",
      "z. c #00A6C1", "x. c #00A7C1", "c. c #00A7C2", "v. c #00A8C2",
      "b. c #00A9C2", "n. c #00AAC3", "m. c #00AFC3", "M. c #00A9C4",
      "N. c #00AAC4", "B. c #00ADC6", "V. c #00ADC7", "C. c #00AEC7",
      "Z. c #00AEC8", "A. c #00AFC8", "S. c #00AFC9", "D. c #10A6C0",
      "F. c #00B4C6", "G. c #00B0C9", "H. c #00B1C9", "J. c #00B0CA",
      "K. c #00B2CA", "L. c #00B2CB", "P. c #00B4CB", "I. c #00B2CD",
      "U. c #00B4CD", "Y. c #00B5CD", "T. c #00B6CD", "R. c #00B7CF",
      "E. c #00B8D0", "W. c #00B9D0", "Q. c #00BBD1", "!. c #00BAD2",
      "~. c #00BBD2", "^. c #00BCD3", "/. c #00BED4", "(. c #00BFD5",
      "). c #21B1C8", "_. c #25BBCF", "`. c #00C0D6", "'. c #00C5DB",
      "]. c #00C8DC", "[. c #00C9DD", "{. c #00C9DE", "}. c #00CADE",
      "|. c #00CBDF", " X c #00CDDF", ".X c #27C2D6", "XX c #00CEE1",
      "oX c #00CEE2", "OX c #00CFE2", "+X c #00CEE4", "@X c #0BCFE2",
      "#X c #00D0E3", "$X c #00D1E4", "%X c #00D1E5", "&X c #00D2E5",
      "*X c #00D1E6", "=X c #00D3E7", "-X c #00D4E6", ";X c #00D5E7",
      ":X c #00D6E8", ">X c #00D6E9", ",X c #00D7E9", "<X c #00D5EB",
      "1X c #00D7EA", "2X c #00D7EB", "3X c #07D5E8", "4X c #00DAEB",
      "5X c #00DAEC", "6X c #00DCED", "7X c #00DCEE", "8X c #12DDEE",
      "9X c #22D4E4", "0X c #39DBEB", "qX c #22E2F0", "wX c #4FCBDB",
      "eX c #61DCE9", "rX c #4EE0ED", "tX c #43E7F3", "yX c #68E3EE",
      "uX c #BDFDFF", "iX c None",
      /* pixels */
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXq.q.h.Y.!.~.W.K.:.iXiXiXiXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX9.q.q.u.A.[.=X>X:X3X9XU.;.iXiXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXq.8.9.9.q.q.w.j.E.{.&X1XtXuX0XK.[ iXiX",
      "iXiXiXiXiXiXiXiXiXiX5.1.4.4.-.*.-.2.9.q.e.a.c.H.`.;XqX8X'.k.0 iX",
      "iXiXiXiXiXiXiXq.5.! G B z t 4 w y l ) 5.q.q.w.u.n.].4X6XOXN.n iX",
      "iXiXiXiXiX9.q.e.D.Z : +   iXiXiXiXiXs U 7.q.q.q.a.^.:X7X%XB.A iX",
      "iXiX^ T *.9.w.h.eX>.iXiXiXiXiXiXiXiXiXv 2.q.q.q.u.Y.-X5X}.v.u iX",
      "iXH = * K 5.t.C.oXF.iXiXiXiXiXiXiXiXiXj 1.q.q.q.t.V.XXoXT.` o iX",
      "iXiXiXiXB 4.r.V.$X XiXiXiXiXiXiXiXiXiXh 1.q.q.q.w.g.R.P.3.% iXiX",
      "iXiXiXiXc 2.w.v.|.,XO iXiXiXiXiXiXiXD M 2.q.q.q.q.w.a./ & iXiXiX",
      "iXiXiXiXl <.q.s.(.>X; iXiXiXiXiXiXJ g ( 9.q.q.q.q.,.e X iXiXiXiX",
      "iXiXiXiXx $.9.y.H.#Xa iXiXiXiXiXM m ) 7.q.q.q.] y @ iXiXiXiXiXiX",
      "iXiXiXiXV ) 9.w.j./.@.m.%.P A Y ..1.9.q.| b = . iXiXiXiXiXiXiXiX",
      "iXiXiXiXiXI 7.q.e.x.U.P.p.6.4.7.( x 2 $   iXiXiXiXiXiXiXiXiXiXiX",
      "iXiXiXiXiXG 5.q.q.)..X&.S p , #   iXiXiXiXiXiXiXiXiXiXiXiXiXiXiX",
      "iXiXiXiXiXm 2.q.q.wXyXo iXiXiXiXiXiXiXiXiXF _ C ' iXiXiXiXiXiXiX",
      "iX+XH.G.B.k 1.q.w._.rXq G.G.G.G.G.G.G.d.z.{ t.~ q.X.G.G.G.H.2XiX",
      "iX*XU.I.L.f ,.q.w.b.@Xr H.J.G.G.G.G.S.i.z.` u._ q. .C.C.C.Z.<XiX",
      "iXiXiXiXiXd +.9.q.l.].i iXiXiXiXiXiXiXiXiXiXW N U iXiXiXiXiXiXiX",
      "iXiXiXiXiXh } 9.0.s.Q.E iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX",
      "iXiXiXiXiXh ) 9.q.e.M.f.iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX",
      "iXiXiXiXiXd ) 9.q.q.y.a.- iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX",
      "iXiXiXiXI j #.9.q.q.q.q.9.=.O.B Q iXiXiXiXiXiXiXiXiX    iXiXiXiX",
      "iXiXo.( L R ..#.1.q.q.q.q.q.q.q.q.( iXiXiXiXiXiXiXiXiX  iXiXiXiX",
      "iXiXiX1 < < 1 1 3 5 7 7 9 8 9 6 9 > iXiXiXiXiXiXiXiXiX  iXiXiXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX  iXiXiXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX  iXiXiX      iXiXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX  iXiXiXiXiXiXiXiXiXiXiXiX  iXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX",
      "iXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiXiX"};

  return QIcon(QPixmap(icon_xpm));
}

QString PowerSliderPlugin::toolTip() const { return QString(); }

QString PowerSliderPlugin::whatsThis() const { return QString(); }

bool PowerSliderPlugin::isContainer() const { return false; }

QString PowerSliderPlugin::domXml() const {
  return QLatin1String("<widget class=\"PowerSlider\" name=\"powerSlider\">\n"
                       " <property name=\"geometry\">\n"
                       "  <rect>\n"
                       "   <x>0</x>\n"
                       "   <y>0</y>\n"
                       "   <width>200</width>\n"
                       "   <height>22</height>\n"
                       "  </rect>\n"
                       " </property>\n"
                       " <property name=\"toolTip\" >\n"
                       "  <string>Power Slider</string>\n"
                       " </property>\n"
                       " <property name=\"whatsThis\" >\n"
                       "  <string>Slider and spinbox all in one"
                       " </string>\n"
                       " </property>\n"
                       "</widget>\n");
}

QString PowerSliderPlugin::includeFile() const {
  return QLatin1String("PowerSlider.hpp");
}
