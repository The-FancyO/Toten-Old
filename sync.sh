git add .

echo "Input git message: "
read message -p

git commit -m $message
git pull
