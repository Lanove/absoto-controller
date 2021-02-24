#define BUILD_VERSION "1.0.0"
#define UPDATE_CHECK_INTERVAL 86400000 // ONE DAY
#define SYSTEM_LOOP_INTERVAL 500
#define HTTP_REQUEST_TIMEOUT 10000
#define MAXIMUM_DISCONNECT_TIME 900000 // Maximum WiFi disconnection time or server request time out before rollback to AP Mode and reset FB

#define TRIGGER_PIN 12
#define ECHO_PIN 2
#define MAX_DISTANCE 200

#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

#define MLX90614_ADDRESS 0x5A

#define _SDA 14
#define _SCL 15

static const char baseUri[] = "192.168.7.102";
static const char recognizeURL[] = "/recognizeFace";
static const int serverPort = 3000;

// This is the minified file of html document to reduce flash usage
// minified is 4857 byte
// unminified is 6358 byte, which is 23.6% saving!
static const char htmlDoc[] PROGMEM = R"=====(
<!DOCTYPE html><html lang="en"> <head> <meta charset="UTF-8"/> <meta name="viewport" content="width=device-width, initial-scale=1.0"/> <title>Otoma Nexus Controller</title> <style>:root{--normalcolor: #011627; --failcolor: #f51000; --successcolor: #00ad17; --main-bg-color: #e4dfda; --second-color: #6a3937; --third-color: #011627; --fourth-color: #9d79bc; --fifth-color: #2374ab;}html{font-family: Helvetica, sans-serif; display: inline-block; text-align: center; color: var(--third-color);}body{margin-top: 50px; margin-left: auto; background-color: var(--main-bg-color);}h1{columns: #444444; margin: 50px auto 30px;}h3{color: #444444; margin-bottom: 50px;}.isian{width: 80%; height: 24px; margin-right: 2%;}.tombolsubmit{margin-top: 2%; margin-left: -2%; width: 84%;}</style> </head> <body> <h2 id="hd">Masukkan informasi</h2> <div style="width: 100vw; height: 100px; margin-bottom: 25px"> <input type="text" placeholder="SSID/Nama WiFi" class="isian" id="ssid"/> <br/><br/> <input type="password" placeholder="Password WiFi" class="isian" id="wfpw"/> <br/><input type="checkbox" id="spw" name="spw" value="show" onclick="showPassword();"/> <label for="spw"> Tampilkan Password</label> <br/><button class="tombolsubmit" onclick="sendInputInfo();" > Submit </button> </div><br/><br/><span style="color: var(--normalcolor)" id="ds"></span> <br/><br/><button onclick="restart();">Restart Kontroller</button> <br/> <h3 style="background-color: red; width: 100vw" id="tm">Belum termuat</h3> <script>function requestAJAX(url, data, callback=function (){}){var xhr=new XMLHttpRequest(); xhr.open("POST", url); xhr.setRequestHeader("Content-type","application/x-www-form-urlencoded"); xhr.send(data); xhr.onload=function (){if (xhr.status==200 && xhr.readyState==4){callback(xhr.responseText);}};}function sendInputInfo(){document.getElementById("ds").innerHTML="Mengolah dan mengirim data yang dimasukkan, kontroller akan memutuskan Access Point, tolong tunggu maksimal 30 detik.<br>Setelah Access Point kontroller ini tersedia kembali, hubungkan wifi tersebut lagi lalu masuk laman ini atau 192.168.4.1 sekali lagi untuk mendapat laporan status."; requestAJAX("accInfo","ssid=" + document.getElementById("ssid").value + "&wfpw=" + document.getElementById("wfpw").value);}function restart(){requestAJAX("restart", "", function (response){document.getElementById("ds").innerHTML="Merestart perangkat dan akan memutus Access Point...";});}function showPassword(){if (document.getElementById("spw").checked) document.getElementById("wfpw").type="text"; else document.getElementById("wfpw").type="password";}window.onload=function (){requestAJAX("reqStatus", "", function (response){response=JSON.parse(response); document.getElementById("ssid").value=response.ssid; document.getElementById("wfpw").value=response.wfpw; document.getElementById("tm").style.backgroundColor="green"; document.getElementById("tm").innerHTML="Berhasil termuat"; if (response.message=="success") document.getElementById("ds").innerHTML="Berhasil tersambung ke WiFi"; else if (response.message=="nocon") document.getElementById("ds").innerHTML="Tidak didapatkan respon dari server, tolong coba lagi sesaat kemudian serta pastikan WiFi anda dapat terkoneksi dengan internet"; else if (response.message=="invwifi") document.getElementById("ds").innerHTML="Gagal menyambung ke WiFi, pastikan SSID dan Password WiFi anda benar lalu coba lagi";});}; </script> </body></html>
)=====";

// CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22