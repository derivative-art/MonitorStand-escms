


//  +---------------------------------------------------------------+
//  |                  WIFI CONFIG FOR secrets.h
//  +---------------------------------------------------------------+
//            ADD these commetned bits to secrets.h
//               and make sure you never commit secrets.h!!!

// 
// Using the WiFi Manager is preferred and avoids reprogramming when your network changes.
// See https://homeding.github.io/#page=/wifimanager.md

// ssid and passPhrase can be used when compiling for a specific environment as a 2. option.

// add you wifi network name and PassPhrase or use WiFi Manager
//#ifndef STASSID
//#define STASSID "change me to your wifi name"
//#define STAPSK "change me to your wifi password"
//#endif
//const char *ssid = STASSID;
//const char *password = STAPSK;





//  +---------------------------------------------------------------+
//  |                  HTML PAGE
//  +---------------------------------------------------------------+
//  Place your fancy web page contents here... 
//        NOTE this is used with printf  so %c %x have special meanings! 
// 
char html_page[] = "<!DOCTYPE html> <html lang=\"en\" class=\"html\" data-theme=\"dark\"><head> <meta charset=\"utf-8\" /> <meta http-equiv=\"X-UA-Compatible\"\
 content=\"IE=edge\" /> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /> \
 <meta http-equiv='refresh' content='2'/> \
 <title> Eye Strain Conscious Monitor Stand </title>   \
<link type=\"application/atom+xml\" rel=\"alternate\" \
href=\"https://derivative-art.github.io/invest_in_futility/feed.xml\" title=\"Passionately indifferent\" /> \
<!-- Favicon --> <link rel=\"apple-touch-icon\" sizes=\"180x180\" href=\"https://derivative-art.github.io/invest_in_futility/assets/images/favicon/apple-touch-icon.png\"> \
<link rel=\"icon\" type=\"image/png\" sizes=\"32x32\" href=\"https://derivative-art.github.io/invest_in_futility/assets/images/favicon/favicon-32x32.png\">\
 <link rel=\"icon\" type=\"image/png\" sizes=\"16x16\" href=\"https://derivative-art.github.io/invest_in_futility/assets/images/favicon/favicon-16x16.png\">\
 <link rel=\"manifest\" href=\"https://derivative-art.github.io/invest_in_futility/assets/images/favicon/site.webmanifest\"> <link rel=\"mask-icon\" \
href=\"https://derivative-art.github.io/invest_in_futility/assets/images/favicon/safari-pinned-tab.svg\" color=\"#5bbad5\"> <link rel=\"shortcut icon\" \
href=\"https://derivative-art.github.io/invest_in_futility/assets/images/favicon/favicon.ico\"> <meta name=\"msapplication-TileColor\" content=\"#00aba9\"> \
<meta name=\"msapplication-config\" content=\"/assets/images/favicon/browserconfig.xml\"> <meta name=\"theme-color\" content=\"#ffffff\"> <!-- Favicon --> \
<link rel=\"stylesheet\" href=\"https://derivative-art.github.io/invest_in_futility/assets/css/main.css\" /> <script type=\"text/javascript\"> \
window.addEventListener('load', themeChange); const currentTheme = localStorage.getItem('theme') ? localStorage.getItem('theme') : \
null; if (currentTheme) document.documentElement.setAttribute('data-theme', currentTheme); function themeChange() { let \
button = document.querySelector('.theme-toggle'); button.addEventListener('click', function (e) { let currentTheme = \
document.documentElement.getAttribute('data-theme'); if (currentTheme === 'dark') { transition(); document.documentElement.setAttribute('data-theme', 'light');\
 localStorage.setItem('theme', 'light'); } else { transition(); document.documentElement.setAttribute('data-theme', 'dark');\
 localStorage.setItem('theme', 'dark'); } }); let transition = () => { document.documentElement.classList.add('transition'); \
window.setTimeout(() => { document.documentElement.classList.remove('transition'); }, 1000); } } </script> </head> <body> \
<main class=\"page-content\" aria-label=\"Content\"> <div class=\"w\"> <header> <ul class=\"horizontal-list\"> <li> <a href=\"https://derivative-art.github.io/about\">\
 about </a> &nbsp;&nbsp; </li> <li> <a href=\"https://derivative-art.github.io/blog\"> blog </a> &nbsp;&nbsp; </li> <li> \
<a href=\"https://derivative-art.github.io/invest_in_futility\"> dead end </a> &nbsp;&nbsp; </li> </ul> <hr> \n\n<h1>Resistentialist Monitor Stand</h1>\n\
    <p>Uptime: %02d:%02d:%02d</p>\n\
    <p> %s Distance: %05d  </span></p>\n\
    <p> %s Movement: %05d</p>\n\
    <! img src=\"/test.svg\" />\n\
  </body>\
</html>";
