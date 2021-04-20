# ClemEngine

## Instruction pour récupérer la branche

D'abord cloner la branche 
```Git
git clone https://github.com/clemb01/ClemEngine
```

Ensuite récupérer les submodules

```Git
git submodule init
git submodule update
```

Il faut ensuite télécharger les fichier nécessaires pour Vulkan (trop volumineux pour les ajouter au repo git)

Aller sur [Vulkan source](https://files.lunarg.com/) et prendre la version que vous avez déjà installée sur votre PC si vous avez déjà Vulkan d'installé, sinon prendre la version la plus récente.

Insuite télécharger le [Vulkan Installer](https://vulkan.lunarg.com/sdk/home) puis l'installer avec le même numéro de version que pour les fichier sources.

Lancer l'éxecutable puis suivre les instructions d'installations.

Pour ce qui est des sources dans le zip, aller dans le dossier ClemEngine/vendor (il doit y avoir entt, Glad, GLFW, etc...) et créé un dossier 'VulkanSDK'. Copier les dossier Bin et Lib du zip dans le dossier que vous avez crée.

Aller maintenant dans le dossier ou a été installer Vulkan ex: 'C:/VulkanSDk/1.2.170/'

Copier/coller l'intégralité du dossier Include dans le dossier crée précédemment ('ClemEngine/vendor/VulkanSDK')

Vous pouvez maintenant allez dans le dossier 'scripts' a la racine de la solution et lancer 'Wind-GenProjetcs.bat', ce qui permettra de générer la solution pour visual studio 2019
