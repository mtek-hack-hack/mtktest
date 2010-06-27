# Parent
PLUTOMMI = TRUE
PLUTOMMI_CHILD = conn_app inet_app media_app mmi_app mmi_framework

# Child
ifdef PLUTOMMI
conn_app = PLUTOMMI
inet_app = PLUTOMMI
media_app = PLUTOMMI
mmi_app = PLUTOMMI
mmi_framework = PLUTOMMI
endif
