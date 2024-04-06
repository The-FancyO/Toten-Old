git add .

read -a message <<< "ENTER GIT MESSAGE: "

git commit -m $message
git pull
