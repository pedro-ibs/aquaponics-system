#!/bin/bash

STATUS='inactive'

while [ true  ]
do
	STATUS=$(systemctl is-active nodered.service)
	if [ "$STATUS" = "active" ]; then
		echo "nodered service is actived"
		break
	else
		echo "wait nodered service"
	fi

	sleep 1
done

echo 'dashboard startup now'

sleep 20

/usr/bin/chromium-browser --app=http://aquaponia42.local:1880/ui --start-fullscreen --force-device-scale-factor=0.50 &
