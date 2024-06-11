git add .

echo 'Enter the commit message:'
read commit_message

git commit -m "$commit_message"

echo 'Enter the name of the branch:'
read branch

git push origin $branch

git pull
