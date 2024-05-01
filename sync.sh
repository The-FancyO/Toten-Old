git add .

echo "Input git message: "

read message

git commit -m ${message[@]}
git push
git pull
