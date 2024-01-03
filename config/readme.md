# **Configuração dos sistema** 

Etapas de preparação da raspberry para funcionamento do node-red e comunicação com o broker


## 1° - [Instalação do node red](https://nodered.org/docs/getting-started/raspberrypi)
```
sudo apt update
sudo apt upgrade

sudo apt install git curl

bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)


sudo systemctl enable nodered.service
sudo systemctl restart nodered.servic

```

<br>

## 2° - Carregando programa
Importe o programa do node-red pelo arquivo [flows.json](flows.json).

<br>


## 3° - Configurar o início automático do dashboard
```

cd

git clone https://github.com/pedro-ibs/aquaponics-system.git

chmod +x ~/aquaponics-system/config/dashboard-startup.sh


```

<br>

No arquivo **`/etc/xdg/lxsession/LXDE-pi/autostart`**  adicionar ao final da linha a execução do script `dashboard-startup.sh`:

```
@lxpanel --profile LXDE-pi
@pcmanfm --desktop --profile LXDE-pi
@xscreensaver -no-splash


# aquaponia42 - 17/11/2023
@~/aquaponics-system/config/dashboard-startup.sh
```