git add .

echo "Input git message: "

read -a message

git commit -m $message[@]
git pull
