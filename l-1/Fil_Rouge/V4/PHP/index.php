<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="../CSS/style.css" />
    <link rel="icon" href="../CSS/Images/logo.png" />
    <title>Musique</title>
</head>
<body>
    <header>
        <div id="Titre">
                <h1>Bibliothèque Musicale</h1>
        </div>
    </header>

    <section id="SectionList">
        
    <?php
$character = file_get_contents("http://145.239.32.254:8081/music/groupes");
$content = json_decode($character);
$albumsGrp = file_get_contents("http://145.239.32.254:8081/music/albums");
$albums = json_decode($albumsGrp);
if(isset($content) && isset($albums)){
    foreach($content as $value){
        if(isset($value)){

            $nomGrp = htmlspecialchars($value->nom);
            $originGrp = htmlspecialchars($value->origin);
            $chanteurGrp = htmlspecialchars($value->chanteur);

        ?>
        <div class="container" id="<?php echo "Container_" . str_replace(' ', '_', $nomGrp);?>">
            <div class="Desc-Badge">
            <img src="<?php echo "../data/Images/" . str_replace(' ', '_', $nomGrp) . ".jpg"?>" alt="<?php echo $nomGrp?>" class="Groupe"/>
            <h2 class="group_name"><?php echo $nomGrp; ?></h2>
            <p class="moreInfo">Cliquez sur la section pour plus d'informations.</p>
            </div>
            <section id="<?php echo str_replace(' ', '_', $nomGrp)?>" style="display: none;">

                <h2 class="bdg-title">Origine</h2>
                <p class="DescriptionGroupe">Le groupe est originaire de <?php echo $originGrp?></p>

                <h2 class="bdg-title">Chanteur du groupe</h2>
                <p class="DescriptionGroupe"><?php echo $chanteurGrp;?></p>

                <h2 class="bdg-title">Genres musicaux du groupe</h2>
                <?php foreach($value->genre as $genre){?><p class="DescriptionGroupe"><?php echo $genre;}?>
                </p>

                <div class="badges">
                <?php foreach($albums as $album){if($album->artiste === $value->id){

                    $nomAlb = htmlspecialchars($album->nom);
                    $sortieAlb = htmlspecialchars($album->sortie);
                    $pisteAlb = htmlspecialchars($album->pistes);

                    ?>
                    <div class="badge">
                        <div class="badge-header"></div>
                        <img src="<?php echo $album->couverture;?>" alt="<?php echo $nomAlb;?>" class="badge-avatar" style="height: 100px; width: 100px;" />
                        <div class="badge-body">
                            <div class="badge-name"><?php echo $nomAlb;?></div>
                            <div class="badge-role">Date de sortie <?php echo $sortieAlb;?></div>
                            <div class="badge-desc"><?php echo $pisteAlb;?> pistes sur l'album</div>
                        </div>
                        <div class="badge-foot"></div>
                    </div>
                <?php }}?>
                </div>
            </section>
        </div>
        <?php
        }
    }
}else{
    ?><p>Erreur lors de la récupération de l'API</p><?php
}
?>
    </section>

    <footer>
        <img class="Social" src="../data/Images/Logo-Uha-blanc.png" alt="UHA"/>
        <img class="Social" src="../data/Images/Twitter.png" alt="Twitter"/>
        <img class="Social" src="../data/Images/GitLab.png" alt="GitLab"/>
    </footer>
    <script src="../JS/ajax.js"></script>
    <script src="../JS/index.js"></script>
</body>
</html>